#include<iostream>
using namespace std;
struct Node
{
    int val;
    Node* next;
};
class SinglyLinkedList
{
    Node* head;
    public:
    SinglyLinkedList()
    {
        head = NULL;
    }
    Node* createNode(int x)
    {
        Node *ptr = new Node;
        ptr->val = x;
        ptr->next = NULL;
        return ptr;
    }
    void insertAtBeg(int val)
    {
        Node *ptr = createNode(val);
        ptr->next = head;
        head = ptr;
    }
    void insertAtEnd(int val)
    {
        Node* ptr = createNode(val);
        Node* temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    int deleteFirst()
    {
        if(head == NULL)
            return -1;
        Node*temp = head;
        head = head->next;
        int ret = temp->val;
        delete temp;
        return ret;
    }
    int deleteLast()
    {
        if(head == NULL || head->next == NULL)
            return -1;
        Node* temp = head;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        Node* ptr = temp->next;
        temp->next = NULL;
        int ret = ptr->val;
        delete ptr;
        return ret;
    }
    void insertAtPos(int val, int pos)
    {
        int count = 1;
        Node* ptr = head;
        while(ptr!=NULL && count < pos - 1)
        {
            ptr = ptr->next;
            count++;
        }
        if(ptr == NULL)
        {
            cout<<"Insertion not possible"<<endl;
            return;
        }
        Node* temp = createNode(val);
        if(pos == 1)
        {
            temp->next = ptr;
            head = temp;
            return;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    int search(int x)
    {
        int i = 1;
        Node* ptr = head;
        while(ptr!=NULL)
        {
            if(ptr->val == x)   
                return i;
            i++;
            ptr = ptr->next;
        }
        return -1; 
    }
    int rsearch(Node* head, int x)
    {
        static int i = 1;
        if(head == NULL)
            return -1;
        if(head->val == x)
            return i;
        //cout<<"HI"<<endl;
        i++;
        return rsearch(head->next, x);
    }
    Node* getHead()
    {
        return head;
    }
    void display()
    {
        Node *ptr = head;
        while(ptr!=NULL)
        {
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
};
int main()
{
    SinglyLinkedList l;
    l.insertAtBeg(20);
    l.insertAtBeg(10);
    l.insertAtEnd(30);
    l.insertAtEnd(40);
    l.display();
    cout<<l.deleteFirst()<<" deleted!"<<endl;
    l.display();
    cout<<l.deleteLast()<<" deleted!"<<endl;
    l.display();
    l.insertAtPos(25, 2);
    l.display();
    cout<<"Element 25 is found at "<<l.rsearch(l.getHead(), 25)<<endl;
    return 0;
}