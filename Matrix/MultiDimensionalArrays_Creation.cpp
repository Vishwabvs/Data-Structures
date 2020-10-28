#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//Method 1
	int arr1[3][2] = {{10, 20},
				    {30, 40},
				    {50, 60}};
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
			cout<<arr1[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	//Method 2
	int arr2[3][2] = {1, 2, 3, 4, 5, 6}; //stores these in row major
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
			cout<<arr2[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	//Method 3
	int arr3[][2] = {100, 200, 300, 400, 500, 600}; //can omit first dimensions
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
			cout<<arr3[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	//Method 4 - Variable Sized Arrays
	int m = 3, n = 2;
	int arr4[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			arr4[i][j] = i*j;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<arr4[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	//Method 5 - Double Pointer (Allocated on Heap)
	m = 3, n = 2;
	int **arr5;
	arr5 = new int*[m];
	for(int i=0;i<m;i++)
		arr5[i] = new int[n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr5[i][j] = 100;
			cout<<arr5[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	//Method 6 - Array of Pointers (Allocated on Stack)
	m = 3, n = 2;
	int *arr6[m];
	for(int i=0;i<m;i++)
		arr6[i] = new int[n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr6[i][j] = 1;
			cout<<arr6[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	//Method 7 - Array of vectors
	m = 3, n = 2;
	vector<int> arr7[m];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			arr7[i].push_back(5);   // Indivual rows are dynamic in size
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr7[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	//Method 8 - Vector of Vectors
	m = 3, n = 2;
	vector<vector<int>> arr8;   // Rows also can be dynamic
	for(int i=0;i<m;i++)
	{
		vector<int> v;
		for(int i=0;i<n;i++)
			v.push_back(25);
		arr8.push_back(v);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr8[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
