//https://www.geeksforgeeks.org/array-rotation/
//Time: O(n)
//Space: O(1)

//Juggling algorithm
#include<iostream>
using namespace std;

int gcd_func(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd_func(b,a%b);
}
int main()
{
    int n = 12,d = 3,q = 0;
    int temp[n];
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};   //Expected O/p:{4, 5, 6, 7, 8, 9, 10, 11, 12,1, 2, 3 }
    d = d%n;


    int gcd = gcd_func(d,n);
    cout<<gcd<<endl;

    for(int i=0;i<gcd;i++)
    {
        int temp = arr[i];
        int j= i;

        while(1)
        {
            int k = j+d;
            if(k>=n)
                k = k-n;
            if(k==i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;

    }



    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
