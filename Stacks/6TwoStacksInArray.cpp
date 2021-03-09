#include<climits>
#include<iostream>
using namespace std;
class TwoStacks
{
    int *arr;
    int n;
    int top1;
    int top2;
    public:
    TwoStacks(int x)
    {
        arr = new int[x];
        n = x;
        top1 = -1;
        top2 = n;
    }
    void push1(int x)
    {
        if(top1 >= top2 - 1)
        {
            cout<<"Stack1 Full..Cant push"<<endl;
            return;
        }
        top1++;
        arr[top1] = x;
    }
    void push2(int x)
    {
        if(top1 >= top2 - 1)
        {
            cout<<"Stack2 Full..Cant push"<<endl;
            return;
        }
        top2--;
        arr[top2] = x;
    }
    int pop1()
    {
        if(top1 == -1)
        {
            cout<<"Stack1 empty cant pop!"<<endl;
            return INT_MAX;
        }
        int x = arr[top1];
        top1--;
        return x;
    }
    int pop2()
    {
        if(top2 == n)
        {
            cout<<"Stack2 empty cant pop!"<<endl;
            return INT_MAX;
        }
        int x = arr[top2];
        top2++;
        return x;
    }
    int size1()
    {
        return top1 + 1;
    }
    int size2()
    {
        return n - top2;
    }
    int top1()
    {
        if(top1 == -1)
        {
            cout<<"Stack1 empty!"<<endl;
            return INT_MAX;
        }
        return arr[top1];
    }
    int top2()
    {
        if(top2 == -1)
        {
            cout<<"Stack2 empty!"<<endl;
            return INT_MAX;
        }
        return arr[top2];
    }
};
int main()
{

    return 0;
}