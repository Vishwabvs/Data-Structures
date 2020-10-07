#include<iostream>
using namespace std;

int counter(int *height, int start, int end)
{
 	int count = 0;
	for(int i=start;i<=end;i++)
    	{
        	if(height[i]<=0)
         		count++;
    	}
    	return count;
}

int rainwater_mysoln(int *arr, int n)
{
	int total = 0;
	int start = 0;
	int end = n-1;
	while(1)
	{
        	while(start<end)
        	{
                 	if(arr[start]>0)
            		{
                			break;
            		}
            		start++;
        	}
        	//cout<<start<<" ";
       		while(end>start)
        	{
                 	if(arr[end]>0)
            		{
                			break;
            		}
            		end--;
        	}
        
        	//cout<<end<<" ";
            	if(start==end)
            		break;
		total+=counter(arr, start, end);
	        
	        for(int i=start;i<=end;i++)
	        {
	            arr[i] = arr[i]-1;
	        }
	        //cout<<endl;
	}
    	return total;
}
int rainwater_basic(int *arr, int n)
{
	//an n^2 solution
	int res=0;
	for(int i=1;i<n-1;i++)
	{
		int lmax = arr[i];
		for(int j=0;j<i;j++)
			lmax = max(lmax, arr[j]);
		int rmax = arr[i];
		for(int j=i+1;j<n;j++)
			rmax = max(rmax, arr[j]);
		res += min(lmax, rmax)-arr[i];
	}
	return res;
}
int rainwater_efficient(int *arr, int n)
{
	int res = 0;
	int lmax[n], rmax[n];
	lmax[0] = arr[0];
	rmax[n-1] = arr[n-1];
	for(int i=1;i<n;i++)
		lmax[i] = max(lmax[i-1], arr[i]);
	for(int i=n-2;i>=0;i--)
		rmax[i] = max(rmax[i+1], arr[i]);
	for(int i=1;i<n-1;i++)
		res += min(lmax[i], rmax[i])-arr[i];
	return res;
}
int main()
{
	//code
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<rainwater_efficient(arr, n)<<endl;
	return 0;
}
