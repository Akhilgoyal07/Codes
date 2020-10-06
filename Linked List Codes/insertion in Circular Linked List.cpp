#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

void printLL(node* head)
{
    cout<<"\nElements of CLL : ";
    if(head)
    {
        node* ptr=head;
        cout<<ptr->data<<" ";
        ptr=ptr->next;
        while(ptr!=head)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<" first node : "<<ptr->data<<endl;
    }
}

//bring position in range of 1 to n+1
int checkSizeAndDoModulo(node* head, int pos)
{
    node* ptr = head;
    int size=1;
    ptr=ptr->next;
    while(ptr!=head)
    {
        size++;
        ptr=ptr->next;
    }

    pos=pos%(size+1);
    if(pos==0)
    {
        pos=size+1;
    }
    return pos;
}

void insertAtOtherPosition(node* head, node* ptr, int pos)
{
    int cp=1;
    while(cp!=pos-1)
    {
        head=head->next;
        cp++;
    }
    ptr->next=head->next;
    head->next=ptr;
}

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

int main()
{
    int ch=1;
    node* head = NULL;
    while(ch==1)
    {
        node*ptr = new node();
        cout<<"\nEnter the value of the new node : ";
        cin>>ptr->data;
        ptr->next=ptr;

        int type;
        cout<<"\nPress 1 for insertion at Start. \nPress 2 for any particular position.";
        cin>>type;

        if(type==1)
        {
            if(!head)
            {
                head=ptr;
            }
            else
            {
                head = insertionAtStart(head, ptr);
            }
        }
        else
        {
            if(!head)
            {
                 head=ptr;
            }
            else
            {
                int pos;
                cout<<"\nEnter the position at which insertion has to be done : ";
                cin>>pos;
                pos = checkSizeAndDoModulo(head, pos);
                cout<<"\nOriginal Position is : "<<pos;
                if(pos==1)
                {
                    head=insertionAtStart(head, ptr);
                }
                else
                {
                    insertAtOtherPosition(head, ptr, pos);
                }
            }
        }

        printLL(head);

        cout<<"\nTo enter more element press 1 : ";
        cin>>ch;
    }
}
