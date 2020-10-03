//Given a number n, find the sum of its digits using recursion
#include<iostream>
using namespace std;
int digitSum(int n)
{
	if(n<10)
		return n;
	return (n%10)+digitSum(n/10);
}
int main()
{
	int n;
	cin>>n;
	cout<<digitSum(n)<<endl;
	return 0;
}
