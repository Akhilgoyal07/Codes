#include <iostream>
using namespace std;

void merge (int a[], int l, int m, int h)
{
    //array1 -> l se m tk
    //array2 ->m+1 se h tk

    int n1 = m-l+1, n2=h-m;

    int L[n1], R[n2];

    for(int i=0; i<n1; i++)
    {
        L[i]=a[l+i];
    }
    for(int i=0; i<n2; i++)
    {
        R[i]=a[m+1+i];
    }

    int il=0, ir=0, j=l;

    while(il<n1 && ir<n2)
    {
        if(L[il]<R[ir])
        {
            a[j]=L[il];
            il++; j++;
        }
        else
        {
            a[j]=R[ir];
            ir++; j++;
        }
    }

    while(il<n1)
    {
        a[j]=L[il];
        il++; j++;
    }
    while(ir<n2)
    {
        a[j]=R[ir];
        ir++; j++;
    }

}

void mergeSort (int a[], int l, int h)
{
    if(l<h)
    {
        int m = l + (h-l)/2;

        mergeSort(a, l, m);
        mergeSort(a, m+1, h);

        merge(a, l, m, h);
    }
}

int main()
{
    int a[7] = {7, 2, 5, 9, 1, 6, 4};

    mergeSort(a, 0, 6);

    for(int i=0; i<7; i++)
    {
        cout<<a[i]<<" ";
    }
}
