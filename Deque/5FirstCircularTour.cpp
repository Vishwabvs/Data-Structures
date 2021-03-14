//Consider an arrangement where n petrol pumps are arranged in a circular manner. We need to find the first petrol pump from where we can visit all petrol pumps and come back to the petrol pump without ever going out of the petrol.
#include<iostream>
using namespace std;
int circularTour(int* petrol, int* dist, int n)
{
    int start = 0, curr = 0;
    int prev = 0;
    for(int i = 0; i < n; i++)
    {
        curr += (petrol[i] - dist[i]);
        if(curr < 0)
        {
            start = i + 1;
            prev += curr;
            curr = 0;
        }
    }
    return ((curr + prev) >= 0) ? (start) : -1;
}
int main()
{
    int n;
    cin>>n;
    int petrol[n];
    int dist[n];
    for(int i = 0; i < n; i++)
        cin>>petrol[i];
    for(int i = 0; i < n; i++)
        cin>>dist[i];
    cout<<circularTour(petrol, dist, n)<<endl;
    return 0;
}