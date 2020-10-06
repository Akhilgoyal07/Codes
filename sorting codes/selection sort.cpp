#include <iostream>
using namespace std;

void selection_sort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_i=i;
        for(int j=i+1; j<n; j++)
        {
            if(a[min_i]>a[j])
            {
                min_i=j;
            }
        }

        int x=a[min_i];
        a[min_i]=a[i];
        a[i]=x;

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

    selection_sort(a, n);

    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}


