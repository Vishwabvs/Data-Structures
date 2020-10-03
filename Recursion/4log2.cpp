//Given a number N, print value of floor(log2 N)
#include<iostream>
using namespace std;
int fun1(int n)
{
	if(n==1)
		return 0;
	return 1+fun1(n/2);
}
int main()
{
	int n;
	cin>>n;
	cout<<fun1(n);
	return 0;
}
