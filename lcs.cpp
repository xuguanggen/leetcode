#include<iostream>
#include<string.h>
using namespace std;
string reserve(string &str)
{
    string result="";
    int len=str.length();
    for(int i=len-1;i>=0;i--)
    {
        result+=str[i];
    }
    return result;
}

int lcs(string &str,string & re_str)
{
    int len= str.length();
    int c[len+1][len+1];
    for(int i=0;i<len+1;i++)
    {
        c[0][i]=0;
        c[i][0]=0;
    }
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(str[i]==re_str[j])
            {
                c[i+1][j+1]=c[i][j]+1;
            }
            else
            {
                c[i+1][j+1]=max(c[i+1][j],c[i][j+1]);
            }
        }
    }
    return c[len][len];
}




int main()
{
    string str = "abcdedcafg";
    string re_str= reserve(str);
    cout<<str<<endl;
    cout<<re_str<<endl;
    int max_lcs = lcs(str,re_str);
    cout<<max_lcs<<endl;
    return 0;
}
