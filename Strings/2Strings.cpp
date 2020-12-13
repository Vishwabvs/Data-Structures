#include<iostream>
#include<cstring>
using namespace std;
void cppStrings()
{
    string str = "geeksforgeeks";
    cout<<str.length()<<" ";
    str = str + "XYZ";
    cout<<str<<" ";
    cout<<str.substr(1, 3)<<" ";
    cout<<str.find("eek")<<endl;

    string s1 = "abc";
    string s2 = "bcd";
    if(s1 == s2)
        cout<<s1<<" and "<<s2<<" are same"<<endl;
    else if(s1 < s2)
        cout<<s1<<" is smaller than "<<s2<<endl;
    else
        cout<<s1<<" is greater than "<<s2<<endl; 
}
int main()
{
    char str[] = "gfg";
    char str2[] = "ab";
    cout<<str<<endl;
    cout<<endl;
    cout<<sizeof(str)<<endl; // will given size+1
    cout<<endl;
    cout<<strlen(str)<<endl;
    cout<<endl;
    cout<<strcmp(str, str2)<<endl;
    cout<<strcmp(str2, str)<<endl;

    char str3[5];
    strcpy(str3, str2);
    cout<<str3<<endl;
    cout<<endl<<"CPP Strings"<<endl;
    cppStrings();
    return 0;
}