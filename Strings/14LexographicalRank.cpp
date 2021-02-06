#include<iostream>
using namespace std;
int fact(int n)
{
    if(n == 1)
        return 1;
    else
        return n*fact(n - 1);
}
int findRank(string& str)
{
    int n = str.length();
    int count[256] = {0};
    int aux[n];
    for(int i = 0; i < n; i++)
    {
        count[str[i]]++;
    }
    for(int i = 1; i < 256; i++)
        count[i] += count[i - 1];
    int mul = fact(n);
    int result = 1;
    for(int i = 0; i < n - 1; i++)
    {
        mul = mul/(n - i);
        result += count[str[i] - 1]*mul;
        for(int j = str[i]; j < 256; j++)
            count[j]--;
    }
    return result;
}
int main()
{
    string str;
    cin>>str;
    cout<<findRank(str)<<endl;
    return 0;
}