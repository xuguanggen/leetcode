#include <iostream>
using namespace std;


int partition(int a[],int p,int r)
{
    int x=a[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(a[j]<=x)
        {
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return i+1;
}

void quickSort(int a[],int p,int r)
{
    if(p<r)
    {
        int q=partition(a,p,r);
        quickSort(a,p,q-1);
        quickSort(a,q+1,r);
    }
}
int main()
{
    int a[]={4,1,3,2,16,9,10,14,8,7};
    cout<<"before sorted:"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    quickSort(a,0,9);
    cout<<"after sorted:"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

