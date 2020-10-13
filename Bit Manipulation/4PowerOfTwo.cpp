//Given a number n, check if it is power of 2
#include<iostream>
#include<cmath>
using namespace std;
bool checkPower(int n)
{
	double d = log2(n);
	if(ceil(d) == floor(d))
		return true;
	return false;
}
bool checkPower2(int n)
{
	if(n ==0)
		return false;
	return ((n&(n-1))==0);
}
int main()
{
	int n;
	cin>>n;
	cout<<checkPower2(n)<<endl;
	return 0;
}
