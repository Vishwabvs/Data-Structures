#include<iostream>
using namespace std;
int gcd_naive(int a, int b)
{
	int res = min(a, b);
	while(res>0)
	{
		if(a%res == 0 && b%res == 0)
			break;
		res--;
	}
	return res;
}
int gcd_basic_euclid(int a, int b)   //using repeated subtraction
{
	while(a!=b)
	{
		if(a>b)
			a = a-b;
		else
			b = b-a;
	}
	return a;
}
int gcd_improvised_euclid(int a,int b)    //using modulo division
{
	if(b == 0)
		return a;
	return gcd_improvised_euclid(b, a%b);
}
int main()
{
	int a, b;
	cin>>a>>b;
	cout<<"GCD Using Naive approach: "<<gcd_naive(a, b)<<endl;
	cout<<"GCD Using Euclid Basic Algorithm: "<<gcd_basic_euclid(a, b)<<endl;
	cout<<"GCD Using Euclid Improvised Algorithm: "<<gcd_improvised_euclid(a, b)<<endl;
	return 0;
}
