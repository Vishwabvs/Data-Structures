#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
	cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i];
    int majority = arr[0], count = 1;
    for(int i=1;i<n;i++)
    {
        if(arr[i] == majority)
            count++;
        else
        {
            if((--count) == 0)
            {
                majority = arr[i];
                count = 1;
            }
        }
    }
    count = 0;
    for(int i=0;i<n;i++)
    {
        if(majority ==arr[i])
            count++;
    }
    count>(n/2)?cout<<majority<<endl:cout<<-1<<endl;
	return 0;
}
