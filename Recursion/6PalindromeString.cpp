//Given a String S, check whether the string is Palindrome or not...
#include<iostream>
using namespace std;
bool isPalindrome(string s, int a, int b)
{
	if(a >= b)
		return true;
	if(s[a]!=s[b])
		return false;
	return isPalindrome(s, a+1, b-1);
}
int main()
{
	string s;
	cin>>s;
	cout<<isPalindrome(s, 0, s.size()-1)<<endl;
	return 0;
}
