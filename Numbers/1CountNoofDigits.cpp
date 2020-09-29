#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int count = 0;
	while(n)
	{
		count++;
		n = n/10;
	}
	cout<<count<<endl;
	return 0;
}
