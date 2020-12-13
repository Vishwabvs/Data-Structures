//Given a string, the task is to find the first character (whose leftmost appearance is first) that repeats.

#include<iostream>
#include<climits>
using namespace std;
int leftMost(string s)
{
    /*This approach requires two traversals
    int count[256] = {0};
    for(int i = 0; i < s.length(); i++)
    {
        if(count[s[i]] == 1)
            return i;
        count[s[i]]++;
    }
    for(int i = 0; i < s.length(); i++)
    {
        if(count[s[i]] > 1)
            return i;
    }
    return -1;*/

    /*This approach takes one traversal from left to right
    int count[256];
    fill(count, count + 256, -1);
    int res = INT_MAX;
    for(int i = 0; i < s.length(); i++)
    {
        if(count[s[i]] != -1)
            res = min(res, count[s[i]]);
        else
            count[s[i]] = i;
    }
    if(res == INT_MAX)
        return -1;
    else    
        return res;*/

    int res;
    bool visited[256];
    fill(visited, visited + 256, false);
    for(int i = s.length() - 1; i >=0; i--)
    {
        if(visited[s[i]])
            res = i;
        else    
            visited[s[i]] = true;
    }
    return res;
}
int main()
{
    string s;
    cin>>s;
    cout<<leftMost(s)<<endl;
}