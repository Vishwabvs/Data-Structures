//Given two strings, check whether a string can be obtained from the other by rotation
#include<iostream>
using namespace std;
string lrotate(string& str, int k)
{
    string result;
    for(int i = k; i < str.length(); i++)
        result += str[i];
    for(int i = 0; i < k; i++)
        result += str[i];
    return result;
}
bool checkRotation(string& str1, string& str2)
{
    //Naive approach: O(n^2)
    for(int i = 0; i < str1.size(); i++)
    {
        if(str2 == lrotate(str1, i))
            return true;
    } 
    return false;
}
bool checkRotation2(string& str1, string& str2)
{
    //Efficient approach: O(n)
    return ((str1.length() == str2.length()) && ((str1+str1).find(str2) != string::npos));
}
int main()
{
    string a, b;
    cin>>a>>b;
    cout<<checkRotation2(a, b);
    return 0;
}