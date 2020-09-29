#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int res = n, temp, sum = 0;
	while(n)
	{
		temp = n%10;
		sum = sum*10 + temp;
		n = n/10;
	}
	if(sum == res)
		cout<<"Yes It is palindrome"<<endl;
	else
		cout<<"No It is not palindrome"<<endl;
	return 0;
}
