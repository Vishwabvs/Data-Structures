//Given a rod of length n and three parameters {a, b, c}, find the maximum no of pieces you can make such that length of every piece is in the set {a, b, c}.
#include<iostream>
using namespace std;
int max_func(int a, int b, int c)
{
	return max(max(a, b), c);
}
int min_func(int a, int b, int c)
{
	return min(min(a, b), c);
}
bool isOdd(int n)
{
	return n%2!=0;
}
int rodCut(int n, int a, int b, int c)
{
	//if(isOdd(n) && !isOdd(a) && !isOdd(b) && !isOdd(c))
	//	return -1;
	//if(n<min_func(a, b, c))
	//	return 0;
	if(n<0)
		return -1;
	if(n==0)
		return 0;		
	int temp = max_func(rodCut(n-a, a, b, c), rodCut(n-b, a, b, c), rodCut(n-c, a, b, c));	
	if(temp == -1)
		return -1;
	return 1+temp;
}
int main()
{
	int n = 23, a = 11, b = 9, c = 12;
	//cin>>n>>a>>b>>c;
	//cout<<max_func(4, 12, 91)<<endl;
	cout<<rodCut(n, a, b, c)<<endl;
	return 0;
}
