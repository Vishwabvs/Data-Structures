//Given n, print numbers from 1 to n
#include<iostream>
using namespace std;
void fun1(int n)
{
	if(n==0)
		return;
	fun1(n-1);
	cout<<n<<" ";
}
int main()
{
	int n;
	cin>>n;
	fun1(n);
}
