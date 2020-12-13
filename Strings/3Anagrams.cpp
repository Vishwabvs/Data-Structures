//Given two strings, we need to check if these strings are Anagram of each other or not.
//Anagrams are obtained by rearranging the letters in the word

#include<iostream>
using namespace std;
const int CHAR = 256;
bool checkAnagrams(string s1, string s2)
{
    if(s1.length()!=s2.length())
        return false;
    int count[CHAR] = {0};
    for(int i = 0; i < s1.length(); i++)
    {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }   
    for(int i = 0; i < CHAR; i++)
    {
        if(count[i]!=0)
            return false;
    }
    return true;
}
int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<checkAnagrams(s1, s2)<<endl;
    return 0;
}