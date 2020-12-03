//Given an array of n elements, count the frequency of each element in the array

#include<iostream>
#include<unordered_map>
using namespace std;
void countFreq(int* arr, int n)
{
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
        m[arr[i]] += 1;
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
    //Following for loop is to print the elements according to the order of input
    /*for(int i = 0; i < n; i++)
    {
        if(m[arr[i]]!=-1)
        {
            cout<<arr[i]<<" "<<m[arr[i]]<<endl;
            m[arr[i]] = -1;
        }
    }*/
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    countFreq(arr, n);
    return 0;
}