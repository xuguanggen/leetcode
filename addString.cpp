# include<iostream>
# include<string.h>
using namespace std;
char* addBinary(char* a, char* b) {
    int a_len=strlen(a);
    int b_len=strlen(b);
    int a_value=0;
    int b_value=0;
    for(int i=0;i<a_len;i++)
    {
        a_value=a_value*2+(a[i]-'0');
    }
    for(int i=0;i<b_len;i++)
    {
        b_value=b_value*2+(b[i]-'0');
    }
    int sum=a_value+b_value;
    char * temp=new char[10000];
    int j=0;
    while(sum>0)
    {
        char ch=sum%2+'0';
        temp[j]=ch;
        sum=sum/2;
        j++;
    }
    char *res=new char[j];
    for(int i=0;i<j;i++)
    {
        res[i]=temp[j-i-1];
    }
    return res;
}
int main()
{
    //char *a="0";
    //char *b="1";
    //cout<<addBinary(a,b)<<endl;
    string str="dcbea";
    cout<<sort(str,str+str.length())<<endl;
    return 0;
}
