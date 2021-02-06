#include<iostream>
using namespace std;
int smallestWindow(string& text, string& patt)
{
    int n = text.length();
    int m = patt.length();
    if(n > m)
        return -1;

    int hash_patt[256] = {0};
    int hash_text[256] = {0};

    for(int i = 0; i < m; i++)
        hash_patt[patt[i]]++;
    for(int i = 0; i < n; i++)
        hash_text[text[i]]++;

    int l = 0, r = 0;
    while(l < n && r < n)
    {
        if()
    }
}
int main()
{
    string text, patt;
    cin>>text>>patt;
    cout<<smallestWindow(text, patt)<<endl;
    return 0;
}