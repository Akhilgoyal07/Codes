#include <iostream>
using namespace std;

struct node
{
    int d;
    node* next = NULL;
};

node* f =NULL;
node* r=NULL;

void enqueue (int e)
{
    node* ptr = new node();
    ptr->d = e;

    if(!r)
    {
        r=f=ptr;
    }
    else
    {
        r->next=ptr;
        r=ptr;
    }
}

void dequeue ()
{
    if(!f)
    {
        cout<<"\nUnderflow. Dequeue can not be performed.";
        return;
    }
    node * ptr = f;
    f=f->next;
    ptr->next=NULL;
    delete(ptr);

    if(!f)
    {
        r=f;
    }

}

int frontofQueue ()
{
    if(!f)
    {
        cout<<"\nQueue is empty.";
        return -1;
    }
    else
    {
        cout<<"\nFront element in the queue is  : "<<f->d;
        return f->d;
    }
}

int main()
{
    int ch=1;
    while(ch)
    {
        int w;
        cout<<"\nEnter you choice. Press \n1 for enqueue. \n2 for dequeue. \n3 for front element.";
        cin>>w;
        if(w==1)
        {
            cout<<"\nEnter the element to be inserted : ";
            int e;
            cin>>e;
            enqueue(e);
        }
        else if(w==2)
        {
            dequeue();
        }
        else if(w==3)
        {
            int x = frontofQueue();
        }
        else
        {
            cout<<"\nEntered choice is incorrect.";
        }
        cout<<"\nTo continue press 1 else any other key.";
        cin>>ch;
    }
}
