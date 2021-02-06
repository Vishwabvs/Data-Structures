//Implementation of KMP string matching algorithm
#include<iostream>
using namespace std;
void fillLPS(string& pattern, int* lps)
{
    lps[0] = 0;
    int len = 0, i = 1, n = pattern.length();
    while(i < n)
    {
        if(pattern[i] == pattern[len])
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
void KMP(string& text, string& pattern)
{
    int n = text.length();
    int m = pattern.length();
    int* lps = new int[m];
    fillLPS(pattern, lps);
    cout<<"LPS Array: ";
    for(int i = 0; i < m; i++)
        cout<<lps[i]<<" ";
    cout<<endl;
    int j = 0, i = 0;
    while(i < n)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if(j == m)
        {
            cout<<i - j<<" ";
            j = lps[j - 1];
        }
        else if(i < n && pattern[j] != text[i])
        {
            if(j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
}
int main()
{
    string text, pattern;
    cin>>text>>pattern;
    KMP(text, pattern);
    return 0;
}