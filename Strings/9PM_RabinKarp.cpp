//Implementation of Rabin Karp algorithm in Pattern Matching
#include<iostream>
using namespace std;
const int d = 256;
const int q = 101;
void patternSearchRabin(string& text, string& pattern)
{
    int n = text.length();
    int m = pattern.length();
    int h = 1;
    for(int i = 1; i < m; i++)
    {
        h = (h * d) % q;
    }
    int t = 0, p = 0;
    for(int i = 0; i < m; i++)
    {
        p = (p*d + pattern[i]) % q;
        t = (t*d + text[i]) % q;
    }
    for(int i = 0; i <= n - m; i++)
    {
        if(p == t)
        {
            int j;
            for(j = 0; j < m; j++)
                if(pattern[j] != text[i + j])
                    break;
            if(j == m)
                cout<<i<<" ";
        }
        if(i < n-m)
        {
            t = (d*(t - text[i]*h) + text[i + m]) % q;
            if(t < 0)
                t = t + q;
        }
    }
}
int main()
{
    string text, pattern;
    cin>>text>>pattern;
    patternSearchRabin(text, pattern);
    return 0;
}