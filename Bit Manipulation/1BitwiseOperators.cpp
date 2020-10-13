//Implementation of Bitwise Operators
#include<iostream>
using namespace std;
int main()
{
	int x = 3, y = 6;
	cout<<"AND"<<endl;
	cout<<x<<" & "<<y<<" = "<<(x&y)<<endl;
	cout<<endl;
	cout<<"OR"<<endl;
	cout<<x<<" | "<<y<<" = "<<(x|y)<<endl;
	cout<<endl;
	cout<<"XOR"<<endl;
	cout<<x<<" ^ "<<y<<" = "<<(x^y)<<endl;
	cout<<endl;
	cout<<"Left Shift Operator"<<endl;
	cout<<x<<" << 1 = "<<(x<<1)<<endl;
	cout<<x<<" << 2 = "<<(x<<2)<<endl;
	y = 4;
	cout<<x<<" << "<<y<<" = "<<(x<<y)<<endl;
	cout<<endl;
	x = 33;
	cout<<"Right Shift Operator"<<endl;
	cout<<x<<" >> 1 = "<<(x>>1)<<endl;
	cout<<x<<" >> 2 = "<<(x>>2)<<endl;
	y = 4;
	cout<<x<<" >> "<<y<<" = "<<(x>>y)<<endl;
	cout<<endl;
	
	cout<<"NOT for unsigned"<<endl;
	unsigned int a = 1;
	cout<<"~"<<a<<" = "<<(~a)<<endl;
	a = 5;
	cout<<"~"<<a<<" = "<<(~a)<<endl;
	cout<<endl;
	cout<<"NOT for signed"<<endl;
	x = 1;
	cout<<"~"<<x<<" = "<<(~x)<<endl;
	x = 5;
	cout<<"~"<<x<<" = "<<(~x)<<endl;
	return 0;
}
