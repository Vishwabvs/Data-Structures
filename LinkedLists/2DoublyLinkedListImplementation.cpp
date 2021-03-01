#include<iostream>
using namespace std;
struct Node
{
    int val;
    Node* next;
    Node* prev;
};
class DoublyLinkedList
{
    Node* head;
    public:
    DoublyLinkedList()
    {
        head = NULL;
    }
    Node* createNode(int val)
    {
        Node* ptr = new Node;
        ptr->val = val;
        ptr->prev = NULL;
        ptr->next = NULL;
        return ptr;
    }
    void insertAtBeg(int val)
    {
        Node* ptr = createNode(val);
        if(head == NULL)
        {
            head = ptr;
            return;
        }
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
    void insertAtEnd(int val)
    {
        Node* ptr = createNode(val);
        if(head == NULL)
        {
            head = ptr;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
    void display()
    {
        Node* ptr = head;
        while(ptr)
        {
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
    Node* getHead()
    {
        return head;
    }
    void reverse()
    {
        if(head == NULL || head->next == NULL)
            return;
        Node* curr = head;
        Node* prev = NULL;
        while(curr != NULL)
        {
            curr->prev = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr->prev;
        }
        head = prev;
    }
    int deleteHead()
    {
        if(head == NULL)
            return -1;
        Node* ptr = head;
        head = head->next;
        head->prev = NULL;
        int ret = ptr->val;
        delete ptr;
        return ret;
    }
    int deleteLast()
    {
        if(head == NULL)
            return -1;
        if(head->next == NULL)
        {
            int ret = head->val;
            delete head;
            return ret;            
        }
        Node* ptr = head;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        Node* temp = ptr;
        int ret = temp->val;
        ptr->prev->next = NULL;
        delete temp;
        return ret;
    }
};
int main()
{
    DoublyLinkedList d;
    d.insertAtEnd(40);
    d.insertAtBeg(10);
    d.insertAtBeg(20);
    d.insertAtBeg(30);
    d.insertAtEnd(50);
    d.display();
    d.reverse();
    d.display();
    cout<<d.deleteHead()<<endl;
    d.display();
    cout<<d.deleteLast()<<endl;
    d.display();
    return 0;
}