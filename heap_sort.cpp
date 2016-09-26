#include<iostream>
#define LEFT(i) 2*i+1
#define RIGHT(i) 2*i+2
using namespace std;



void max_heapify(int a[],int heap_size,int i)
{
    int l=LEFT(i);
    int r=RIGHT(i);
    int largest=i;
    if(l<heap_size&&a[l]>a[i])
        largest=l;
    if(r<heap_size&&a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        int temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        max_heapify(a,heap_size,largest);
    }
}


void build_max_heap(int a[],int len)
{
    for(int i=len/2-1;i>=0;i--)
    {
        max_heapify(a,len,i);
    }
}

void heap_sort(int a[],int len)
{
    build_max_heap(a,len);
    for(int i=len-1;i>=1;i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        len=len-1;
        max_heapify(a,len,0);
    }
    cout<<"after sorted:"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
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
    heap_sort(a,10);
    return 0;
}
