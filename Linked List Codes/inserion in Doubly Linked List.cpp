#include <iostream>
using namespace std;


struct node
{
    int data;
    node* pre;
    node* next;
};

//printing ll
void printLL(node* head)
{
    cout<<"Elements of Doubly Linked List : ";
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

//printing ll in reverse order
void printLLR(node* last)
{
    cout<<"Elements of Doubly Linked List in reverse order : ";
    while(last)
    {
        cout<<last->data<<" ";
        last = last->pre;
    }
    cout<<endl;
}

node* insertionAtStart(node* head, node* ptr)
{
    //checking if ll is empty
    if(head)
    {
        ptr->next=head;
        head->pre=ptr;
        head = ptr;
    }
    else
    {
        head=ptr;
    }
    return head;
}

node* insertionAtLast(node* last, node* ptr)
{
    //checking if DLL is empty
    if(last)
    {
        ptr->pre = last;
        last->next = ptr;
        last = ptr;
    }
    else
    {
        last = ptr;
    }
    return last;
}

int checkPos(node* head, int pos)
{
    int size=0;
    while(head)
    {
        size++;
        head=head->next;
    }
    if(pos==1)
    {
        return 1;
    }
    //range n+1
    else if(pos==size+1)
    {
        return 3;
    }
    //range 2 se n
    else if(pos>0 && pos<=size)
    {
        return 2;
    }
    //out of range
    else
    {
        return 0;
    }
}

void insertAtMiddle(node* head, node* ptr, int pos)
{
    int cp=1;
    node* p=head;
    while(cp!=pos)
    {
        p=p->next;
        cp++;
    }
    ptr->next = p;
    ptr->pre = p->pre;
    p->pre->next = ptr;
    p->pre=ptr;
}

int checkData (node* head, int d)
{
    while(head && head->data!=d)
    {
        head=head->next;
    }
    //data not found
    if(!head)
    {
        return 0;
    }
    //if insertion at last
    else if(!head->next)
    {
        return 3;
    }
    // insertion at middle;
    else
    {
        return 2;
    }
}

int main()
{
    int nextElement=1;
    node* head = NULL;
    node* last = NULL;

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
            head = insertionAtStart(head, ptr);
            if(!last)
            {
                last=head;
            }
        }
        else if(type==2)
        {
            last = insertionAtLast(last, ptr);
            if(!head)
            {
                head=last;
            }
        }
        else if(type==3)
        {
            int pos;
            cout<<"Enter a position for insertion : ";
            cin>>pos;

            int pt = checkPos(head, pos);
            cout<<"\nPosition of pt : "<<pt<<endl;
            if(pt==1)
            {
                head = insertionAtStart(head, ptr);
                if(!last)
                {
                    last=head;
                }
            }
            else if(pt==2)
            {
                insertAtMiddle(head, ptr, pos);
            }
            else if(pt==3)
            {
                last = insertionAtLast(last, ptr);
                if(!head)
                {
                    head=last;
                }
            }
            else
            {
                cout<<"\nThe input for position is wrong. Insertion can not be performed.";
            }
            //head = insertionAtParticularPosition(head, ptr, pos);

        }
        else if(type==4)
        {
            int d;
            cout<<"\nEnter the data after which insertion has to be done : ";
            cin>>d;

            int dt = checkData(head, d);

            cout<<"\nPosition of dt : "<<dt<<endl;
        }

        printLL(head);
        printLLR(last);

        cout<<"\nTo enter more data press 1 :";
        cin>>nextElement;
    }
}
