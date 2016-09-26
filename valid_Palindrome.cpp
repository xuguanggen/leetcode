#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;

bool IsChar(char c)
    {
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            return true;
        return false;
    }
    bool IsDigit(char c)
    {
        if(c>='0'&&c<='9')
            return true;
        return false;
    }
    string transform(string &s)
    {
        string str="";
        int len=s.length();
        for(int i=0;i<len;i++)
        {
           if(IsChar(s[i]))
           {
               if(s[i]>='A'&&s[i]<='Z')
               {
                   str+=s[i]-('A'-'a');
               }else
                {
                    str+=s[i];
                }
           }
           if(IsDigit(s[i]))
           {
               str+=s[i];
           }
        }
        return str;
    }
    bool isPalindrome(string s) {
        if(s==""||s.length()==1)
            return true;
        s=transform(s);
       stack<char>ss;
       queue<char>q;
       int i=0;
       int len=s.length();
       for(i=0;i<len;i++)
       {
           if(IsDigit(s[i])||(s[i]>='a'&&s[i]<='z'))
           {
               ss.push(s[i]);
               q.push(s[i]);
           }
       }
       while(!ss.empty())
       {
           char s_temp=ss.top();
           char q_temp=q.front();
           ss.pop();
           q.pop();
           if(s_temp!=q_temp)
            {
                return false;
            }
       }
       return true;
    }

int main()
{
    string str="0P";
    //string str="A man, a plan, a canal: Panama";
	bool result=isPalindrome(str);
	cout<<result<<endl;
    return 0;
}
