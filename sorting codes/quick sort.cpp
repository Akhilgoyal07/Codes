#include <iostream>
using namespace std;

//this function will place the pivot at correct position all elements on left will be smaller
//and all elements on right will be greater
int partition(int a[], int l, int h)
{
    int p=h;
    int rp=l, gp=l;

    while(gp<h)
    {
        while(rp<h && a[rp]<=a[p])
        {
            rp++;
        }

        gp=rp;
        while(gp<h && a[gp]>a[p])
        {
            gp++;
        }
        swap(a[gp], a[rp]);

        //debugging
        cout<<"\n";
        for(int i=l; i<=h; i++)
        {
            cout<<a[i]<<" ";
        }
    }
    return rp;
}

//Quick Sort function
void QS(int a[], int l, int h)
{
    if(l<h)
    {
        int p = partition (a, l, h);
        QS(a, l, p-1);
        QS(a, p+1, h);
    }
}

int main()
{
    int a[7]={1, 8, 3, 9, 4, 5, 7};

    //for taking input
    //for(int i=0; i<n; i++)
    //{
    //    cin>>a[i];
    //}

    //quick sort function as 3 argument array, starting index(always 0) & end index(n-1)
    QS(a, 0, 6);

    cout<<"\n Sorted array : ";
    for(int i=0; i<7; i++)
    {
        cout<<a[i]<<" ";
    }
}
