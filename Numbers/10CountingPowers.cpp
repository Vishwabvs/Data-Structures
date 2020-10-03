//compute x^n
#include<iostream>
using namespace std;
int power_naive(int x, int n)
{
	int res = 1;
	for(int i=0;i<n;i++)
		res = res*x;
	return res;
}
int power_opt(int x, int n)
{
	if(n==0)
		return 1;
	int temp = power_opt(x, n/2);
	temp = temp*temp;
	if(n%2==0)
		return temp;
	else
		return x*temp;
}
int main()
{
	int n, x;
	cin>>x>>n;
	cout<<power_opt(x, n)<<endl;
	return 0;
}
