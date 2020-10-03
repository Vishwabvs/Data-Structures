//Given 3 rods and N disks, the task is to move the entire stack to another rod using recursion.
#include<iostream>
using namespace std;
void toi(int n, char src, char dest, char aux)
{
	if(n==1)
	{
		cout<<"Move Disc "<<n<<" from "<<src<<" to "<<dest<<endl;
		return;
	}
	toi(n-1, src, aux, dest);
	//cout<<"Move Disc "<<n<<" from "<<src<<" to "<<aux<<endl;
	cout<<"Move Disc "<<n<<" from "<<src<<" to "<<dest<<endl;
	toi(n-1, aux, dest, src);
}
int main()
{
	int n;
	cin>>n;
	toi(n, 'A', 'C', 'B');
	return 0;
}
