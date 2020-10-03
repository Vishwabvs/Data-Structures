//Given a String s, print all possible subsets of it(in any order).
#include<iostream>
using namespace std;
void printSubsets(string s, int index = 0, string curr = "")
{
	if(s.size() == index)
	{
		cout<<curr<<" ";
		//cout<<curr+s[index]<<" ";
		return;
	}
	printSubsets(s, index+1, curr);
	printSubsets(s, index+1, curr+s[index]);
}
int main()
{
	string s;
	cin>>s;
	printSubsets(s);
}
