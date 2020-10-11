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

node* swapNode(node* head, int pos1, int pos2)
{
    if(pos1==pos2)
    {
        cout<<"\nEnter different Position";
        return head;
    }

    node* pp1=NULL;
    node* p1=head;
    int pos=1;
    while(p1 && pos!=pos1)
    {
        pp1=p1;
        p1=p1->next;
        pos++;
    }

    node* pp2=NULL;
    node* p2=head;
    pos=1;
    while(p2 && pos!=pos2)
    {
        pp2=p2;
        p2=p2->next;
        pos++;
    }

    //pp1 is not Null that is p1 is not the first node;
    if(pp1)
    {
        pp1->next=p2;
    }
    else
    {
        head=p2;
    }

    //pp2 is not Null that is p2 is not the first node;
    if(pp2)
    {
        pp2->next=p1;
    }
    else
    {
        head=p1;
    }

    node* n = p1->next;
    p1->next=p2->next;
    p2->next=n;

    return head;
}
int main()
{
    int nextElement=1;
    node* head = NULL;

    //inserting element in Linked List
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

    //swapping of nodes in Linked List
    int nextSwap=1;
    while(nextSwap==1)
    {
        //take input from user of position of nodes;
        cout<<"\n Enter the position of nodes to be swap : ";
        int pos1, pos2;
        cin>>pos1>>pos2;

        //swap
        head = swapNode(head, pos1, pos2);

        cout<<"\nTo do more swap of nodes press 1 : ";
        cin>>nextSwap;

        printLL(head);
    }

    return 0;
}


