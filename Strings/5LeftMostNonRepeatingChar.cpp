//Given a string, the task is to find the leftmost character that does not repeat.
#include<iostream>
#include<climits>
using namespace std;
int nonRepeating(string s)
{
    /*This requires Two traversals
    int count[256] = {0};
    for(int i = 0; i < s.length(); i++)
    {
        count[s[i]]++;
    }
    for(int i = 0; i < s.length(); i++)
    {
        if(count[s[i]] == 1)
            return i;
    }
    return -1;*/
    //Takes only one traversal
    int count[256];
    fill(count, count + 256, -1);
    for(int i = 0; i < s.length(); i++)
    {
        if(count[s[i]] == -1)
            count[s[i]] = i;
        else
            count[s[i]] = -2;
    }
    int res = INT_MAX;
    for(int i = 0; i < 256; i++)
        if(count[i] >= 0)
            res = min(res, count[i]);
    if(res == INT_MAX)
        return -1;
    return res;
}
int main()
{
    string s;
    cin>>s;
    cout<<nonRepeating(s)<<endl;
    return 0;
}