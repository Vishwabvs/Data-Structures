//Given a 2D Matrix, Traverse the matrix in spiral form and print the result
//https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/


#include<iostream>
using namespace std;

//Solution 1 : Efficient
void printSpiral(int *mat[], int R, int C)
{
	int top = 0, left = 0, bottom = R - 1, right = C - 1;

	while(top <= bottom && left <= right)
	{
		for(int i = left; i <= right; i++)
			cout << mat[top][i] << " ";

		top++;

		for(int i = top; i <= bottom; i++)
			cout << mat[i][right] << " " ;
		
		right--;

		if(top <= bottom){
		for(int i = right; i >= left; i--)
			cout << mat[bottom][i] << " ";

		bottom--;
		}

		if(left <= right){
		for(int i = bottom; i >= top; i--)
			cout << mat[i][left] << " ";

		left++;
		}			
	}
}

// Solution 2 : Using recursion
void printSpiral(int *arr[], int r_start, int r_end, int c_start, int c_end)
{
    if(r_start>r_end || c_start>c_end)
        return;
    if(r_start == r_end)
    {
        for(int j=c_start;j<=c_end;j++)
            cout<<arr[r_start][j]<<" ";
        return;
    }
    if(c_start == c_end)
    {
        for(int i=r_start;i<=r_end;i++)
            cout<<arr[i][c_start]<<" ";
        return;
    }    
    for(int j=c_start;j<=c_end;j++)
    {
        cout<<arr[r_start][j]<<" ";
    }
    for(int i=r_start+1;i<=r_end;i++)
    {
        cout
        <<arr[i][c_end]<<" ";
    }
    for(int j=c_end-1;j>=c_start;j--)
    {
        cout<<arr[r_end][j]<<" ";
    }
    for(int i=r_end-1;i>r_start;i--)
    {
        cout<<arr[i][c_start]<<" ";
    }
    printSpiral(arr, r_start+1, r_end-1, c_start+1, c_end-1);
}
void spiralTraversal(int *arr[], int m, int n)
{
    printSpiral(arr, 0, m-1, 0, n-1);
}
int main()
{
    int m, n;
    cin>>m>>n;
    int *arr[m];
    for(int i=0;i<m;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    spiralTraversal(arr, m, n);
    cout<<endl;
    return 0;
}  