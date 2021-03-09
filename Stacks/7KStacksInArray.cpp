#include<iostream>
#include<climits>
using namespace std;
class KStacks
{
    int* arr, *top, *next;
    int K, freeTop, cap;
    public:
    KStacks(int k1, int size)
    {
        K = k1;
        cap = size;
        arr = new int[cap];
        top = new int[K];
        next = new int[cap];
        for(int i = 0; i < K; i++)
            top[i] = -1;
        freeTop = 0;
        for(int i = 0; i < cap - 1; i++)
        {
            next[i] = i + 1;
        }
        next[cap - 1] = -1;
    }
    bool isFull()
    {
        return (freeTop == -1);
    }
    bool isEmpty(int sn)
    {
        return (top[sn] == -1);
    }
    void push(int x, int sn)
    {
        if(isFull())
            return;
        int i = freeTop;
        freeTop = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = x;
    }
    int pop(int sn)
    {
        if(isEmpty(sn))
            return INT_MAX;
        int i = top[sn];
        top[sn] = next[i];
        next[i] = freeTop;
        freeTop = i;
        return arr[i];
    }
};
int main() 
{ 
    // Let us create 3 stacks in an array of size 10 
    int k = 3, n = 10; 
    KStacks ks(k, n); 
  
    // Let us put some items in stack number 2 
    ks.push(15, 2); 
    ks.push(45, 2); 
  
    // Let us put some items in stack number 1 
    ks.push(17, 1); 
    ks.push(49, 1); 
    ks.push(39, 1); 
  
    // Let us put some items in stack number 0 
    ks.push(11, 0); 
    ks.push(9, 0); 
    ks.push(7, 0); 
  
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl; 
  
    return 0; 
} 