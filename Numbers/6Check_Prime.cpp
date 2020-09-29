#include<iostream>
using namespace std;
bool isPrime_naive(int n)
{
	if(n==1)
		return false;
	for(int i = 2;i<n;i++)
	{
		if(n%i == 0)
			return false;
	}
	return true;
}
bool isPrime_optimized(int n)
{
	if(n==1)
		return false;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i == 0)
			return false;
	}
	return true;
}
int isPrime_best(int n)
{
	if(n==1)
		return false;
	if(n==2||n==3)
		return true;
	if(n%2 == 0 || n%3 == 0)
		return false;
	for(int i = 5;i*i<=n;i = i+6)
	{
		if(n%i == 0 || n%(i+2) == 0)
			return false;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	if(isPrime_optimized(n))
		cout<<"Prime"<<endl;
	else
		cout<<"Not a Prime"<<endl;
	return 0;
}
