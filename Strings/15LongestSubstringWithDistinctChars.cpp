#include<iostream>
#include<vector>
using namespace std;
int findsubstr(string& str)
{
    int n = str.length(), res = 0;
    vector<int> prev(256, -1);
    int i = 0, maxEnd;
    for(int j = 0; j < n; j++)
    {
        i = max(i, prev[str[j]] + 1);
        maxEnd = j - i + 1;
        res = max(res, maxEnd);
        prev[str[j]] = j;
    }
    return res;
}
int main()
{
    string str;
    cin>>str;
    cout<<findsubstr(str)<<endl;
    return 0;
}