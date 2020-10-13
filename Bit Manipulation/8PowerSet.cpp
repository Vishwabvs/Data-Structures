//Given a string s, generate its power set

//This problem is done using bit manipulation
#include<iostream>
#include<cmath>
using namespace std;
void printSubsets(string str)
{
	int n = str.size();
	int powSize = pow(2, n);
	for(int i=0;i<powSize;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
				cout<<str[j];
		}
		cout<<endl;
	}
}
int main()
{
	string str;
	cin>>str;
	printSubsets(str);
	return 0;
}
