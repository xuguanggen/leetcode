#include<iostream>
#include<string.h>
using namespace std;

string precess(string str)
{
    string newstr="$#";
    for(int i=0;i<str.length();i++)
    {
        newstr+=str[i];
        newstr+="#";
    }
    return newstr;
}


string method_1(string &s)
{
    int maxlen=1;
    int begin=0;
    int len=s.length();
    bool table[len][len]={false};
    for(int i=0;i<len;i++)
        table[i][i]=true;
    for(int i=0;i<len-1;i++)
    {
        if(s[i]==s[i+1])
        {
            table[i][i+1]=true;
            maxlen=2;
            begin=2;
        }
    }
    for(int cur_len=3;cur_len<=len;cur_len++)
    {
        for(int i=0;i<=len-cur_len;i++)
        {
            if(s[i]==s[i+cur_len-1]&&table[i+1][i+cur_len-2])
            {
                begin=i;
                maxlen=cur_len;
                table[i][i+cur_len-1]=true;
            }
        }
    }
    return s.substr(begin,maxlen);
}

string addR(string &s,int i,int j)
{
    while(i>=0&&j<=s.length()-1&&s[i]==s[j])
    {
        i--;
        j++;
    }
    return s.substr(i+1,j-(i+1));
}
string Method_2(string & s)
{
    int maxlen=1;
    string longest="";
    int len=s.length();
    int i=0;
    while(i<len-1)
    {
        string p1=addR(s,i,i);
        if(p1.length()>longest.length())
        {
            maxlen=p1.length();
            longest=p1;
        }
        string p2=addR(s,i,i+1);
        if(p2.length()>longest.length())
        {
            maxlen=p2.length();
            longest=p2;
        }
        i++;
    }
    return longest;
}


string preprocess(string &str)
{
    string s="#";
    for(int i=0;i<str.length();i++)
    {   
        s+=str[i];
        s+="#";
    }
    return s;        
}

string Method_3(string &str)
{
    string newstr=preprocess(str);
    return newstr;
}







int main()
{
    string str="1123311332432";
    cout<<"原:"<<str<<endl;
    string result = method_1(str);
    cout<<"Method_1:\t"<<result<<endl;
    result=Method_2(str);
    cout<<"Method_2:\t"<<result<<endl;
    result=Method_3(str);
    cout<<"Method_3:\t"<<result<<endl;
    return 0;
}
