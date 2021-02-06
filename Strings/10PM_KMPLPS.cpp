//Implementation of LPS(longest proper prefix suffix) array for KMP pattern matching matching algoritm
#include<iostream>
using namespace std;
int longPropPreSuff(string& str, int n)
{
    for(int len = n - 1; len >=0; len--)
    {
        bool flag = false;
        for(int i = 0; i < len; i++)
        {
            if(str[i] != str[n - len + i])
            {
                flag = true;
                break;
            }
        }
        if(flag == false)
            return len;
    }
    return 0;
}
void fillLPS1(string& s, int* lps)
{
    //This approach takes O(n^3) time
    for(int i = 0; i < s.length(); i++)
        lps[i] = longPropPreSuff(s, i + 1);
}
void fillLPS2(string& s, int* lps)
{
    //O(n) approach
    lps[0] = 0;
    int n = s.length();
    int len = 0;
    int i = 1;
    while(i < n)
    {
        if(s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}
int main()
{
    string str;
    cin>>str;
    int lps[str.length()];
    //fillLPS1(str, lps);
    fillLPS2(str, lps);
    for(int i = 0; i < str.length(); i++)
        cout<<lps[i]<<" ";
    return 0;
}