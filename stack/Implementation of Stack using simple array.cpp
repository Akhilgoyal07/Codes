#include <iostream>
using namespace std;

int top=-1;
int capacity = 10;
int stack[10];

void push(int data)
{
    if(capacity==top+1)
    {
        cout<<"\n Overflow. Data not pushed.";
    }
    else
    {
        top++;
        stack[top]=data;
    }
}

int pop()
{
    if(top==-1)
    {
        cout<<"\n Underflow. No data in the stack";
        return -1;
    }
    else
    {
        top--;
        return stack[top+1];
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
