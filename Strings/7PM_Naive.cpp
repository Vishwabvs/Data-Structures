//Given a pattern and a text, we need to print all occurrences of the pattern in the text.
//Expected Time Complexity : O((m+n-1)*m)

#include<iostream>
using namespace std;
void patternSearchNaive(string &text, string &pattern)
{
    int m = pattern.length();
    int n = text.length();
    for(int i = 0; i + m - 1 < n; i++)
    {
        int j;
        for(j = 0; j < m; j++)
        {
            if(text[i + j] != pattern[j])
            {
                break;
            }
        }
        if(j == m)
            cout<<i<<" ";
    }
}
int main()
{
    string text, pattern;
    cin>>text>>pattern;
    patternSearchNaive(text, pattern);
    return 0;
}