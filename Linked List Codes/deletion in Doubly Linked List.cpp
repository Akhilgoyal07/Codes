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
    cout<<"\nElements of Doubly Linked List : ";
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
    cout<<"\nElements of Doubly Linked List in reverse order : ";
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

node* deleteFirstNode(node* head)
{
    node* ptr=head;
    head=head->next;
    head->pre=NULL;
    ptr->next=NULL;
    delete(ptr);
    return head;
}

node* deleteLastNode (node* last)
{
    node* ptr=last;
    last=last->pre;
    last->next=NULL;
    ptr->pre=NULL;
    delete(ptr);
    return last;
}

int checkPos(node* head, int p)
{
    if(head && p>0)
    {
        if(p==1 && !head->next)
        {
            return 1;
        }
        else if(p==1)
        {
            return 2;
        }
        else
        {
            int cp=1;
            while(cp!=p && head)
            {
                head=head->next;
                cp++;
            }
            if(!head)
            {
                return 0;
            }
            else if(!head->next)
            {
                return 3;
            }
            else
            {
                return 4;
            }
        }

        return (head?true:false);
    }
    return 0;
}

void deleteMiddleNode(node* head, int p)
{
    node* ptr=head;
    int cp=1;
    while(cp!=p)
    {
        ptr=ptr->next;
        cp++;
    }
    ptr->next->pre=ptr->pre;
    ptr->pre->next=ptr->next;
    ptr->next=ptr->pre=NULL;
    delete(ptr);
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

        head = insertionAtStart(head, ptr);
        if(!last)
        {
            last=head;
        }
        cout<<"\nTo enter more element press 1 : ";
        cin>>nextElement;
    }

    nextElement=1;

    while(nextElement==1)
    {
        int type;
        //type
        cout<<"\n To delete first node press 1.\n To delete last node press 2.\n To delete node at particular position press 3.";
        cin>>type;
        int i;
        if(type==1)
        {
            if(!head)
            {
                cout<<"\nLinked List is empty. Deletion can not be performed.";
            }
            else if(head==last)
            {
                delete(head);
                head=last=NULL;
            }
            else
            {
                head=deleteFirstNode(head);
            }
        }
        else if(type==2)
        {
            if(!last)
            {
                cout<<"\nLinked List is empty. Deletion can not be performed.";
            }
            else if(head==last)
            {
                delete(head);
                head=last=NULL;
            }
            else
            {
                last = deleteLastNode(last);
            }
        }
        else if(type==3)
        {
            int p;
            cout<<"\n Enter the position of node to be deleted : ";
            cin>>p;
            int validPos = checkPos(head, p);
            if(validPos==1)
            {
                head=last=NULL;
            }
            else if(validPos==2)
            {
                head=deleteFirstNode(head);
            }
            else if(validPos==3)
            {
                last=deleteLastNode(last);
            }
            else if(validPos==4)
            {
                deleteMiddleNode(head, p);
            }
            else
            {
                cout<<"\nEntered position is incorrect. Deletion can not be performed.";
            }
        }
        else
        {
            cout<<"\nThe choice entered is incorrect. Please enter a valid choice.";
        }

        printLL(head);
        //cin>>i;
        printLLR(last);
        //cin>>i;
        cout<<"\nTo delete more element press 1 : ";
        cin>>nextElement;
    }

}
