#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* head=NULL;

void push(int data)
{
    node* p = new node();
    p->data = data;

    p->next = head;
    head=p;
}

int pop()
{
    if(!head)
    {
        cout<<"\n Underflow. No data in the stack";
        return -1;
    }
    else
    {
        node* p = head;
        head=head->next;

        return p->data;
    }
}

int main()
{
    int input=1;

    while(input==1)
    {
        cout<<"\n Enter your choice. \n1 for push. \n2 for pop\n";
        int choice;
        cin>>choice;

        if(choice==1)
        {
            int data;
            cout<<"\nEnter the data to be pushed :";
            cin>>data;
            push(data);
        }
        else if(choice==2)
        {
            cout<< "\nThe topmost data which is popped : "<<pop()<<endl;
        }
        else
        {
            cout<<"Entered choice is incorrect. Please enter a valid choice";
            continue;
        }

        cout<<"To enter more input press 1";
        cin>>input;
    }
}

