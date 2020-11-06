//Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.
//https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form-set-2-o1-extra-space/

//Solution
void rearrange(int *arr, int n) 
{ 
	
	// Your code here
	int max_element = arr[n-1] + 1;
	int max_index = n-1, min_index = 0;
	for(int i=0;i<n;i++)
	{
	    if(i%2 == 0)
	    {
	        arr[i] += arr[max_index] % max_element * max_element;
	        max_index--;
	    }
	    else
	    {
	        arr[i] += arr[min_index] % max_element * max_element;
	        min_index++;
	    }
	}
	for(int i=0;i<n;i++)
	{
	    arr[i] = arr[i]/max_element;
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	rearrange(arr, n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}