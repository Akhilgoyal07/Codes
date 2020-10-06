#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* insertionAtStart(node* head, node* ptr)
{
    node* p=head;
    while(p->next!=head)
    {
        p=p->next;
    }
    ptr->next=head;
    p->next=ptr;
    head=ptr;

    return head;
}

void printCLL(node* head)
{
    if(!head)
    {
        cout<<"\nCircular Linked List is empty.";
    }
    else
    {
        cout<<"\nElements of Circular Linked List : ";
        cout<<head->data<<" ";
        node* ptr=head->next;

        while(ptr!=head)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }

        cout<<"First Node : "<<ptr->data;
    }
}

node* deleteFirstNode(node* head)
{
    if(head == head->next)
    {
        delete(head);
        return NULL;
    }
    else
    {
        node* ptr = head->next;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=head->next;
        delete(head);
        // head=ptr->next;
        // return head;
        return ptr->next;
    }
}

int bringInActualSize(node* head, int pos)
{
    node* ptr=head->next;
    int no=1;
    while(ptr!=head)
    {
        no++;
        ptr=ptr->next;
    }
    //0 - no-1
    pos=pos%no;

    // 1 - no
    if(pos==0)
    {
        pos=no;
    }
    return pos;
}

void deleteOtherNode(node* head, int pos)
{
    int cp=1;
    node* ptr = head;

    while(cp!=pos-1)
    {
        ptr=ptr->next;
        cp++;
    }

    node*p = ptr->next;
    ptr->next=p->next;
    delete(p);
}

int main()
{
    int ch=1;
    node* head = NULL;
    while(ch==1)
    {
        node* ptr = new node();
        cout<<"\nEnter the value of the new node : " ;
        cin>>ptr->data;
        ptr->next=ptr;

        if(!head)
        {
            head=ptr;
        }
        else
        {
            head = insertionAtStart(head, ptr);
        }

        cout<<"\nTo enter more element press 1 : ";
        cin>>ch;
    }

    printCLL(head);
    ch=1;
    while(ch == 1)
    {
        cout<<"\n Press 1 to delete first Node \n Press 2 to delete node at particular location : ";
        int type;
        cin>>type;

        if(!head)
        {
            cout<<"\nLinked List is Empty. Deletion can not be performed.";
        }
        else if(type == 1)
        {
            head = deleteFirstNode(head);
        }
        else if(type==2)
        {
            int pos;
            cout<<"\nEnter the position at which deletion has to be performed : ";
            cin>>pos;
            pos = bringInActualSize(head, pos);
            cout<<"\n Actual Position : "<<pos;

            if(pos==1)
            {
                head = deleteFirstNode(head);
            }
            else
            {
                deleteOtherNode(head, pos);
            }
        }
        else
        {
            cout<<"\nEntered Choice is incorrect.";
        }

        printCLL(head);
        cout<<"\nTo delete more element press 1 : ";
        cin>>ch;
    }

}
