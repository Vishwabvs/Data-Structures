//Given an integer n and a number k, check if kth bit from right of binary representation of n is set or not.
#include<bits/stdc++.h>
using namespace std;
void func1(int n, int k)
{
	//using left shift
	if(n&(1<<(k-1)))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}
void func2(int n, int k)
{
	//using right shift
	if((n>>(k-1))&1)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}
int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	func1(n, k);
	func2(n, k);
	return 0;	
}
