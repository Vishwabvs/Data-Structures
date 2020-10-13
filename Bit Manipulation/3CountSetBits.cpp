//Given an integer n, count the no of bits set in the binary representation of number n
#include<iostream>
using namespace std;
int countSetBits1(int n)
{
	if(n==1 || n==0)
		return n;
	else
		return n%2+countSetBits1(n/2);
}
int countSetBits2(int n)
{
	int count=0;
	while(n)
	{
		if((n&1)==1)
		{
			count++;
		}
		//count += (n&1);   Instead of writing the if condition
		n = n>>1;
	}
	return count;
}
int countSetBits3(int n)
{
	int res = 0;
	while(n)
	{
		n = (n & (n-1));
		res++;
	}
	return res;
}
int table[256];
void initialize()
{
	table[0] = 0;
	for(int i=1;i<256;i++)
		table[i] = (i&1) + table[i/2];
}
int countSetBits4(int n)
{
	//This method works in O(1) time assuming initialize is called before 
	int res = table[n & 0xff];
	n = n>>8;
	res += table[n & 0xff];
	n = n>>8;
	res += table[n & 0xff];
	n = n>>8;
	res += table[n & 0xff];
	return res;
}
int main()
{
	int n;
	cin>>n;
	initialize();
	cout<<countSetBits4(n)<<endl;
	return 0;
}
