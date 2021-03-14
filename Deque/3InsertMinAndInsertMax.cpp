/*designing a data structure that supports the following operations in O(1) time.
1) Get Minimum
2) Get Maximum
3) Insert Minimum
4) Insert Maximum
5) Delete Minimum
6) Delete Maximum*/

#include<iostream>
#include<deque>
using namespace std;
class Deque
{
    deque<int> dq;
    public:
    Deque(){}
    void insertMin(int x)
    {
        dq.push_front(x);
    }
    void insertMax(int x)
    {
        dq.push_back(x);
    }
    int getMin()
    {
        return dq.front();
    }
    int getMax()
    {
        return dq.back();
    }
    int extractMin()
    {
        int temp = dq.front();
        dq.pop_front();
        return temp;
    }
    int extractMax()
    {
        int temp = dq.back();
        dq.pop_back();
        return temp;
    }
};
int main()
{
    Deque dq;
    dq.insertMin(5);
    dq.insertMax(10);
    dq.insertMin(3);
    dq.insertMax(15);
    dq.insertMin(2);
    cout<<dq.getMin()<<endl;
    cout<<dq.getMax()<<endl;
    return 0;
}