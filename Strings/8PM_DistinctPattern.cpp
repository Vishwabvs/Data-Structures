//Given a pattern with distinct characters and a text, we need to print all occurrences of the pattern in the text. 
//This talks about improved Naive pattern searching with Theta(n) time complexity

#include<iostream>
using namespace std;
void patternSearchDistinct(string &text, string &pattern)
{
    int n = text.length();
    int m = pattern.length();
    for(int i = 0; i + m - 1 < n;)
    {
        int j;
        for(j = 0; j < m; j++)
        {
            if(text[i + j] != pattern[j])
                break;
        }
        if(j == m)
            cout<<i<<" ";
        if(j == 0)
            i++;
        else
            i = i + j;        
    }
}
int main()
{
    string text, pattern;
    cin>>text>>pattern;
    patternSearchDistinct(text, pattern);
    return 0;
}