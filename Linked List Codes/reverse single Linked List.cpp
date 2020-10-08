#include <iostream>
using namespace std;

struct node
{
    //data field
    int data;
    //reference field
    node* next=NULL;
};

//at start
node* insertionAtStart(node* head, node* ptr)
{
    ptr->next=head;
    head=ptr;
    return head;
}

//printing linked list
void printLL(node* head)
{
    cout<<"\nData in linked list : ";
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

node* reverseLL(node* ptr, node* pre)
{
    if(ptr)
    {
        //cout<<"\n value at node : "<<ptr->data;
        node* h= reverseLL(ptr->next, ptr);
        ptr->next=pre;
        //cout<<"\n value at node : "<<ptr->data;
        return h;
    }
    else
    {
        return pre;
    }
}

int main()
{
    int nextElement=1;
    node* head = NULL;

    while(nextElement==1)
    {
        int d;
        cout<<"Enter data:";
        cin>>d;
        node* ptr = new node();
        ptr->data=d;

        head=insertionAtStart(head, ptr);

        cout<<"\nTo Enter more element press 1 : ";
        cin>>nextElement;
    }

    printLL(head);

    //reverse Linked List using loop
    if(head->next)
    {
        node* pre = NULL;
        node* ptr = head;

        while(ptr)
        {
            node* n = ptr->next;
            ptr->next = pre;
            pre=ptr;
            ptr=n;
        }
        head=pre;
    }

    //reverse linked list using recursion
    if(head->next)
    {
        head = reverseLL(head, NULL);
    }

    cout<<"\nAfter Reversing : ";
    printLL(head);

}
