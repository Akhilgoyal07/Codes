#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next = NULL;
};

void printll(node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

node* deleteFirstNode(node* head)
{
    if(head)
    {
        node* ptr=head;
        head=head->next;
        delete(ptr);
    }
    else
    {
        cout<<"\nLinked List is Empty. Deletion can not be performed\n";
    }
    return head;
}

node* deleteLastNode(node* head)
{
    if(head)
    {
        if(head->next)
        {
            node* ptr=head;
            node*pre = NULL;
            while(ptr->next)
            {
                pre=ptr;
                ptr=ptr->next;
            }
            pre->next=ptr->next;
            delete(ptr);
        }
        else
        {
            head = deleteFirstNode(head);
        }
    }
    else
    {
        cout<<"\nLinked List is Empty. Deletion can not be performed\n";
    }
    return head;
}

bool findPosition(node* head, int pos)
{
    int length=0;
    while(head)
    {
        length++;
        head=head->next;
    }
    return (length>=pos ? true : false);
}



node* deleteNodeAtParticularPosition(node* head, int pos)
{
    bool positionExists = findPosition(head, pos);
    if(positionExists)
    {
        if(pos==1)
        {
            head = deleteFirstNode(head);
        }
        else
        {
            node* ptr=head;
            node*pre = NULL;
            int index=1;
            while(index!=pos)
            {
                pre=ptr;
                ptr=ptr->next;
                index++;
            }
            pre->next=ptr->next;
            delete(ptr);
        }
    }
    else
    {
        cout<<"\nPosition do not exist in Linked List. Deletion can not be performed\n";
    }
    return head;
}

bool findValue(node* head, int value)
{
    while(head && head->data!=value  )
    {
        head=head->next;
    }
    //wrong way
    //if(head->data==value)
    if(head)
    {
        return true;
    }
    return false;
}

node* deleteNodeWithParticularValue (node* head, int value)
{
    bool valueExists = findValue(head, value);
    cout<<valueExists<<endl;
    if(valueExists)
    {
        if(head->data==value)
        {
            head = deleteFirstNode(head);
        }
        else
        {
            node* ptr=head;
            node*pre = NULL;
            while(ptr->data!=value)
            {
                pre=ptr;
                ptr=ptr->next;
            }
            pre->next=ptr->next;
            delete(ptr);
        }
    }
    else
    {
        cout<<"\Value do not exist in Linked List. Deletion can not be performed\n";
    }
    return head;
}

int main()
{
    int input=1;
    node* head = NULL;
    while(input==1)
    {
        node* ptr = new node();
        int d;
        cout<<"Enter the data : ";
        cin>>d;
        ptr->data=d;
        //insertion at start
        ptr->next=head;
        head=ptr;
        cout<<"To enter more data press 1: ";
        cin>>input;
    }

    cout<<"\n\nElements of Linked List : ";
    printll(head);

    input=1;
    while(input)
    {
        int no;
        cout<<"\n\nChoose your option.\n To delete first node press 1 \n To delete last node press 2\n";
        cout<<" To delete node at particular position press 3\n";
        cout<<" To delete node with particular value press 4\n";
        cin>>no;
        if(no==1)
        {
            head = deleteFirstNode(head);
        }
        else if(no==2)
        {
            head = deleteLastNode(head);
        }
        else if(no==3)
        {
            int pos;
            cout<<"\nEnter the position of the node to be deleted : ";
            cin>>pos;
            head = deleteNodeAtParticularPosition(head, pos);
        }
        else if(no==4)
        {
            int value;
            cout<<"\nEnter the value of the node to be deleted : ";
            cin>>value;
            head = deleteNodeWithParticularValue(head, value);
        }
        else
        {
            cout<<"\nEntered choice is wrong. Please enter a valid choice next time.";
        }
        cout<<"\n\nElements of Linked List : ";
        printll(head);

        cout<<"\n\nTo perform more delete operation press 1 :";
        cin>>input;
    }




}
