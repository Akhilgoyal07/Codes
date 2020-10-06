#include <iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n-i+1; j++)  //n-i+1 = 7-2+1=6
        {
            if(a[j-1]>a[j])
            {
                int x=a[j];
                a[j]=a[j-1];
                a[j-1]=x;
            }
        }
        cout<<"Iteration no : "<<i<<" ";
        for(int j=0; j<n; j++)
        {
             cout<<a[j]<<" ";
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

    bubble_sort(a, n);

    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}
