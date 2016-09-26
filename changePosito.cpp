#include<iostream>
using namespace std;
void print(int *number,int length)
{
    for(int i=0;i<length;i++)
    {
        cout<<number[i]<<" ";
    }
    cout<<endl;
}



void method_1(int *number,int length)
{
    cout<<"前:"<<endl;
    print(number,length);
    ////////////////////////////////////////////////////
    for(int i=0;i<length-1;i++)
    {
        if(number[i]%2==0)
        {
            int temp=number[i];
            for(int j=i+1;j<=length-1;j++)
            {
                number[j-1]=number[j];
            }
            number[length-1]=temp;
        }
    }
    ///////////////////////////////////////////////////
    cout<<"后:"<<endl;
    print(number,length);
}


void method_2(int *number,int length)
{
    cout<<"前:"<<endl;
    print(number,length);
    ////////////////////////////////////////////////////////
    int first = 0;
    int second = length-1;
    while(first<second)
    {
        while(number[first]%2!=0&&first<second)
        {
            first++;
        }
        while(number[second]%2!=1&&first<second)
        {
            second--;
        }
        if(first<second)
        {
            int temp=number[first];
            number[first]=number[second];
            number[second]=temp;
        }
    }
    ///////////////////////////////////////////////////////
    cout<<"后:"<<endl;
    print(number,length);
}

void method_3(int *number,int length)
{
    cout<<"前:"<<endl;
    print(number,length);
    /////////////////////////////////////////////////////////
    for(int i =1;i<length;i++)
    {
        if(number[i]%2==1)
        {
            int x=i;
            while(x>=1 && number[x-1]%2!=1)
            {
                int temp=number[x-1];
                number[x-1]=number[x];
                number[x]=temp;
                x--;
            }
        }
    }
    /////////////////////////////////////////////////////////
    cout<<"后:"<<endl;
    print(number,length);

}






int main()
{
    int length =10;
    int *number = new int [length];
    for(int i=0;i<length;i++)
        number[i]=i+1;
    //method_1(number,length);
    //method_2(number,length);
    method_3(number,length);
    return 0;
}
