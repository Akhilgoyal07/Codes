#include <iostream>
using namespace std;

struct node
{
    //data field
    int data;
    //reference field
    node* next=NULL;
};

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

//at start
node* insertionAtStart(node* head, node* ptr)
{
    ptr->next=head;
    head=ptr;
    return head;
}

//at last
node* insertionAtLast (node* head, node* ptr)
{
    if(!head)
    {
        return insertionAtStart(head, ptr);
        //ptr->next=head;
        //head=ptr;
        //return head;
    }
    else
    {
        node* p = head;
        while(p->next)
        {
            p=p->next;
        }
        p->next=ptr;
        return head;
    }
}

//at particular position
node* insertionAtParticularPosition(node* head, node* ptr, int pos)
{
    if(!head || pos==1)
    {
        if(pos!=1)
        {
            cout<<"\nEntered position is wrong. Insertion at Last is done.";
        }
        return insertionAtStart(head, ptr);
    }
    else
    {
        //linked size 4 user pos 9
        int i=1;
        node* p=head;
        while(i!=pos-1 && p)
        {
            p=p->next;
            i++;
        }
        if(p)
        {
            ptr->next=p->next;
            p->next=ptr;
            return head;
        }
        else
        {
            cout<<"\nEntered position is wrong. Insertion at Last is done.";
            return insertionAtLast(head, ptr);
        }

    }
}

//after a particular element
node* insertionAfterParticularElement(node* head, node* ptr, int ele)
{
    node* p =head;
    while(p && p->data!=ele)
    {
        p=p->next;
    }
    if(!p)
    {
        cout<<"\nEntered element is not present in linked list. Insertion at Last is done.";
        return insertionAtLast(head, ptr);
    }
    else
    {
        ptr->next=p->next;
        p->next=ptr;
        return head;
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

        int type;
        cout<<"Enter\n 1 for insertion at start.\n 2 for insertion at last\n 3 for insertion at particular position.\n 4 for insertion after particular element.\n";
        cin>>type;

        if(type==1)
        {
            head=insertionAtStart(head, ptr);
        }
        else if(type==2)
        {
            head = insertionAtLast(head, ptr);
        }
        else if(type==3)
        {
            int pos;
            cout<<"\nEnter the position at which you want to insert the data: ";
            cin>>pos;
            head = insertionAtParticularPosition(head, ptr, pos);
        }
        else if(type==4)
        {
            int ele;
            printLL(head);
            cout<<"\nEnter the element after which you want to insert the data: ";
            cin>>ele;
            head = insertionAfterParticularElement(head, ptr, ele);
        }
        else
        {
            cout<<"\nEnter choice is incorrect. Enter a valid choice."<<endl;
        }

        printLL(head);

        cout<<"\nTo enter more data press 1 :";
        cin>>nextElement;
    }
    printLL(head);
}
