//Prints factors of a given number
#include<iostream>
using namespace std;
void printfactors_rec(int n, int i)
{
	if(i*i>n)
		return;
	if(n%i==0)
	{
		cout<<i<<" ";
	}
	printfactors_rec(n, i+1);
	if(n%i==0 && i!=(n/i))
	{
		cout<<n/i<<" ";
	}
}
void printfactors_iter(int n)
{
	int i;
	for(i=1;i*i<n;i++)
	{
		if(n%i==0)
			cout<<i<<" ";
	}
	for(;i>=1;i--)
	{
		if(n%i==0)
			cout<<n/i<<" ";
	}
}
void printfactors_naive(int n)
{
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
			cout<<i<<" ";
	}
}

int main()
{
	int n;
	cin>>n;
	printfactors_iter(n);
	return 0;
}
