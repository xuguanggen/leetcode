#include<iostream>
#include<string.h>
using namespace std;

char* addOne(char *ch)
{
    int len=strlen(ch);
    cout<<len<<endl;
    int i=len-1;
    int add=1;
    for(i=len-1;i>=0;i--)
    {
        int temp= ch[i]-'0'+add;
        //cout<<temp<<endl;
        if(temp>=10)
        {
            ch[i]=temp%10+'0';
            add=temp/10;
        }else{
            ch[i]=temp+'0';
            add=0;
        }
    }
    //for(i=0;i<len;i++)
    //{
    //    if(ch[i]!='0')
    //    {
    //        for(int j=i;j<len;j++)
    //            cout<<ch[j];
    //        continue;
    //    }
    //}
    //cout<<endl;
    return ch;
}
bool Increment(char*number)
{
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength= strlen(number);
    for(int i=nLength-1;i>=0;i--)
    {
        int nSum = number[i]-'0'+nTakeOver;
        if(i==nLength-1)
        {
            nSum++;
        }
        if(nSum>=10)
        {
            if(i==0)
            {
                isOverflow=true;
            }else{
                nSum -= 10;
                nTakeOver =1;
                number[i]='0'+nSum;
            }
        }else{
            number[i]='0'+nSum;
            break;
        }
    }
    return isOverflow;
}

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

void PrintToMaxOfDigits(int n)
{
    if(n<=0)
    {
        return ;
    }
    char *number = new char[n+1];
    memset(number,'0',n);
    number[n]='\0';
    
    while(!Increment(number))
    {
        PrintNumber(number);
    }
}


int main()
{
    PrintToMaxOfDigits(3);
    return 0;   
}
