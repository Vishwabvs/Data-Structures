//Given a number n, print all prime numbers less than or equal to n
#include<iostream>
using namespace std;
bool isPrime(int n)
{
	if(n==2 || n==3)
		return true;
	if(n%3==0||n%2==0)
		return false;
	for(int i=5;i*i<=n;i++)
	{
		if(n%i==0||n%(i+2)==0)
			return false;
	}
	return true;
}

void primesn_naive(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(isPrime(i))
		{
			cout<<i<<" ";
		}
	}
	cout<<endl;
}

void primeseive(int n)
{
	bool arr[n+1];
	for(int i=0;i<=n;i++)
		arr[i] = true;
	for(int i=2;i*i<=n;i++)
	{
		if(arr[i])
		{
			for(int j = i*i;j<=n;j = j+i)
			{
				arr[j] = false;
			}
		}
	}
	for(int i = 2;i<=n;i++)
		if(arr[i])
			cout<<i<<" ";
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	primeseive(n);
	return 0;
}
