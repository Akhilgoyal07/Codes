#include <iostream>
using namespace std;

int * q;
int capacity;
int cs=0, f=-1, r=-1;

void enqueue (int e)
{
    if(cs==capacity)
    {
        cout<<"\nOverflow. Enqueue can not be performed.";
        return;
    }
    r=(r+1)%capacity;
    q[r]=e;
    cs++;
    if(cs==1)
    {
        f=r;
    }
}

void dequeue ()
{
    if(cs==0)
    {
        cout<<"\nUnderflow. Dequeue can not be performed.";
        return;
    }
    f=(f+1)%capacity;
    cs--;
    if(cs==0)
    {
        r=f=-1;
    }
}

int frontofQueue ()
{
    if(cs==0)
    {
        cout<<"\nQueue is empty.";
        return -1;
    }
    cout<<"\nFront element in the queue is  : "<<q[f];
    return q[f];
}

int main()
{
    cout<<"Maximum no of element that can be present in queue : ";
    cin>>capacity;
    q=new int[capacity];

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
