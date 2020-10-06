#include <iostream>
using namespace std;

void merge(int a[], int n1, int b[], int n2)
{
    int last;

    //b array from last element till first element
    for(int i=n2-1; i>=0; i--)
    {
        last=a[n1-1];
        int j=n1-2;
        while(b[i]<a[j] && j>=0) //j=-1
        {
            a[j+1]=a[j];
            j--;
        }

        if(j!=n1-2 || last>b[i])
        {
            a[j+1]=b[i];
            b[i]=last;
        }

    }

}

int main()
{
    int a[6] = {1, 5, 9, 10, 15, 20};
    int b[4] = {2, 3, 8, 13};

    merge(a, 6, b, 4);

    for(int i=0; i<6; i++)
    {
        cout<<a[i]<<" ";
    }
    for(int i=0; i<4; i++)
    {
        cout<<b[i]<<" ";
    }
}
