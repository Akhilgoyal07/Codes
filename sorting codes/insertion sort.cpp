#include <iostream>
using namespace std;

void insertion_sort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j>0; j--)
        {
            if(a[j]<a[j-1])
            {
                int x=a[j];
                a[j]=a[j-1];
                a[j-1]=x;
            }
        }
        cout<<"Iteration no "<<i<<" : ";
        for(int i=0; i<n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    insertion_sort(a, n);

    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}

