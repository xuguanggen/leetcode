#include <iostream>
#include<string.h>
using namespace std;





void PrintNumber(char*number)
{
    bool isBegining0 = true;
    int nLength= strlen(number);
    for(int i=0;i<nLength;i++)
    {
        if(isBegining0 && number[i]!='0')
            isBegining0 = false;
        if(!isBegining0)
        {
            cout<<number[i];
        }
    }
    cout<<endl;
}
void function(char * number,int length,int index)
{
    if(index==length-1)
    {
        PrintNumber(number);
        return;
    }
    for(int i=0;i<10;i++)
    {
        number[index]=i+'0';
        function(number,length,index+1);
    }
}

void Print1ToMaxOfDigits(int n)
{
    if(n<=0)
        return ;
    char *number = new char[n+1];
    number[n]='\0';
    function(number,n,0);
    //for(int i=0;i<10;i++)
    //{
    //    function(number,n,0);
    //}
}
int main()
{
    Print1ToMaxOfDigits(3);
    return 0;
}
