//Given a string, reverse its words.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*void reverse(string &s, int start, int end)
{
    while(start < end)
    {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}*/
void revWords(string &s)
{
    int start = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' ')
        {
            //reverse(s, start, i - 1);
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
    reverse(s.begin() + start, s.begin() + s.length());
    reverse(s.begin(), s.end());
}
int main()
{
    string s;
    getline(cin, s);
    revWords(s);
    cout<<s;
    return 0;
}