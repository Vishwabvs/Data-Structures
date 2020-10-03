//Given a string, print all permutations of it.
#include<iostream>
using namespace std;
void swap(string &str, int a, int b)
{
	char temp = str[a];
	str[a] = str[b];
	str[b] = temp;
}
void printFunc(string& str, int first, int last)
{
	if(first==last)
	{
		cout<<str<<" ";
		return;
	}
	for(int i=first;i<=last;i++)
	{
		swap(str, first, i);
		printFunc(str, first+1, last);
		swap(str, first, i);		
	}
	
}
int main()
{
	string str;
	cin>>str;
	printFunc(str, 0, str.size()-1);
	return 0;
}
