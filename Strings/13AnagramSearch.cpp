//Given a text and a pattern, the task is to find if there is an anagram of pattern present in text.

#include<iostream>
using namespace std;
bool areAnagrams(string& text, string& pattern, int i)
{
    int count[256] = {0};
    for(int j = 0; j < pattern.length(); j++)
    {
        count[pattern[j]]++;
        count[text[i + j]]--;
    }
    for(int j = 0; j < 256; j++)
    {
        if(count[j]!=0)
            return false;
    }
    return true;
}
bool anagramSearch(string& text, string& pattern)
{
    //Naive Approach: O(n^2)
    int n = text.length();
    int m = pattern.length();
    for(int i = 0; i <= n - m; i++)
    {
        if(areAnagrams(text, pattern, i))
            return true;
    }
    return false;
}
bool areSame(int* arr1, int* arr2)
{
    for(int i = 0; i < 256; i++)
    {
        if(arr1[i] != arr2[i])
            return false;
    }
    return true;
}
bool anagramSearch2(string& text, string& pattern)
{
    int countText[256] = {0};
    int countPattern[256] = {0};
    int n = text.length();
    int m = pattern.length();
    for(int i = 0; i < m; i++)
    {
        countPattern[pattern[i]]++;
        countText[text[i]]++;
    }
    for(int i = m; i < n; i++)
    {
        if(areSame(countPattern, countText))
            return true;
        countText[text[i]]++;
        countText[text[i - m]]--;
    }
    return false;
}
int main()
{
    string text, pattern;
    cin>>text>>pattern;
    cout<<anagramSearch2(text, pattern)<<endl;
}