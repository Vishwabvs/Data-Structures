// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> sortByFreq(int arr[],int n);

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    vector<int> v;
	    v = sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

// } Driver Code Ends


//Complete this function
//Return the sorted array

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if(a.second > b.second)
        return true;
    return false;
}

vector<int> sortByFreq(int arr[],int n)
{
    //Your code here
    vector<int> result;
    map<int, int> m;
    for(int i = 0; i < n; i++)
        m[arr[i]]++;
    vector<pair<int, int>> aux;
    for(auto i : m)
    {
        aux.push_back(make_pair(i.first, i.second));
    }
    int sz = aux.size();
    sort(aux.begin(), aux.end(), cmp);
    for(auto it = aux.begin(); it!=aux.end();it++)
    {
        for(int j = 0; j < it->second; j++)
            result.push_back(it->first);
    }
    return result;
}