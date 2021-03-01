#include<iostream>
using namespace std;
struct Node
{
    int val;
    Node* next;
};
class SinglyCircularLinkedList
{
    Node* head;
    public:
    SinglyCircularLinkedList()
    {
        head = NULL;
    }
    Node* createNode(int val)
    {
        Node* ptr = new Node;
        ptr->val = val;
        ptr->next = NULL;
        return ptr;
    }
    void insertAtBeg(int val)
    {
        Node* temp = createNode(val);
        if(head == NULL)
        {
            head = temp;
            head->next = head;
            return;
        }
        /*Node* ptr = head;
        while(ptr->next!=head)
        {
            ptr = ptr->next;
        }
        temp->next = head;
        ptr->next = temp;
        head = temp;*/
        int aux = head->val;
        head->val = temp->val;
        temp->val = aux;
        temp->next = head->next;
        head->next = temp;    
    }
    void insertAtEnd(int val)
    {
        Node* temp = createNode(val);
        if(head == NULL)
        {
            head = temp;
            head->next = head;
            return;
        }
        /*Node *ptr = head;
        while(ptr->next!=head)
        {
            ptr = ptr->next;
        }
        temp->next = head;
        ptr->next = temp;*/
        int aux = head->val;
        head->val = temp->val;
        temp->val = aux;
        temp->next = head->next;
        head->next = temp;
        head = head->next;
    }
    int deleteHead()
    {
        if(head == NULL)
            return -1;
        if(head->next == head)
        {
            int ret = head->val;
            delete head;
            return ret;
        }
        /*
        Node *curr = head;
        while(curr->next!=head)
            curr = curr->next;
        curr->next = head->next;
        int ret = head->val;
        delete head;
        head = curr->next;
        return ret;
        */
        int ret = head->val;
        head->val = head->next->val;
        head->next = head->next->next;
        return ret;
    }
    int deleteKthNode(int k)
    {
        if(head == NULL)
            return -1;
        /*if(head->next == head && k == 1)
        {
            int ret = head->val;
            delete head;
            return ret;
        }
        if(k == 1)
        {
            int ret = head->val;
            head->val = head->next->val;
            head->next = head->next->next;
            return ret;
        }*/
        if(k == 1)
            return deleteHead();
        int counter = 1;
        Node*ptr = head;
        while(counter < k - 1 && ptr->next != head)
        {
            ptr = ptr->next;
            counter++;
        }
        if(ptr->next == head && counter != k - 2)
            return -1;
        Node* temp = ptr->next;
        int ret = temp->val;
        ptr->next = temp->next;
        delete temp;
        return ret;
    }
    void display()
    {
        if(head == NULL)
            return;
        /*cout<<head->val<<" ";
        Node* ptr = head->next;
        while(ptr!=head)
        {
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        }*/
        Node* ptr = head;
        do
        {
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        } while (ptr!=head);
        cout<<endl;
    }
};
int main()
{
    SinglyCircularLinkedList sll;
    sll.insertAtBeg(10);
    sll.insertAtBeg(20);
    sll.insertAtBeg(30);
    sll.insertAtBeg(40);
    sll.display();
    sll.insertAtEnd(50);
    sll.insertAtEnd(60);
    sll.display();
    cout<<sll.deleteHead()<<endl;
    sll.display();
    cout<<sll.deleteKthNode(1)<<endl;
    sll.display();
    return 0;
}