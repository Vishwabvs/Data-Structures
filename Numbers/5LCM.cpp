//lcm of a and b
#include<iostream>
using namespace std;
int lcm_naive(int a, int b)
{
	int res = max(a, b);
	while(true)
	{
		if(res%a == 0 && res%b == 0)
			return res;
		res++;
	}
	return res;
}
int gcd(int a, int b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}
int lcm_using_gcd(int a, int b)
{
	return a*b/gcd(a, b);
}
int main()
{
	int a, b;
	cin>>a>>b;
	cout<<"LCM Using Naive approach: "<<lcm_naive(a, b)<<endl;
	cout<<"LCM Using GCD: "<<lcm_using_gcd(a, b)<<endl;
	return 0;
}
