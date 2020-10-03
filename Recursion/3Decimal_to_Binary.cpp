//Given a decimal number n, prints its binary equivalent
#include<iostream>
using namespace std;
void fun1(int n)
{
	if(n==0)
		return;
	fun1(n/2);
	cout<<n%2;
}
int main()
{
	int n;
	cin>>n;
	fun1(n);
	return 0;
}
