#include<iostream>
#include<cstring>
using namespace std;

int dp[100];

int fact(int n)
{
    if(n==0)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n] = n*fact(n-1);
}



void printPascal(int n)
{
    int lookup[100][100] = {0};
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<n-i-1;j++)
            cout<<" ";
        for(int j=0;j<=i;j++)
        {
            int d1 = fact(i-j);
            int d2 = fact(j);
            int n1 = fact(i);
            cout<<n1/(d1*d2)<<" ";
            lookup[i][j] = n1/(d1*d2);
        }
        cout<<endl;
    }
}

int main()
{
    memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
    printPascal(n);
	return 0;
}
