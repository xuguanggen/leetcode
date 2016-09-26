#include<iostream>
#include<stack>
#include<queue>
using namespace std;
bool IsDigit(char c)
    {
        if(c>='0'&&c<='9')
        {
            return true;
        }
        return false;
    }
    int calculate(string s) {
        int len=s.length();
        stack<int> v_stack;
        stack<char> c_stack;
        int i=0,temp=0;
        for(i=0;i<len;i++)
        {
            if(i==0)
            {
                if(IsDigit(s[i]))
                {
                    temp=s[i]-'0';
                }
            }else
            {
               if(IsDigit(s[i]))
               {
                   if(IsDigit(s[i-1]))
                   {
                       temp=temp*10+s[i]-'0';
                   }else
                   {
                       temp=s[i]-'0';
                   }
               }else
               {
                   v_stack.push(temp);
                   c_stack.push(s[i]);
               }
            }
        }
        v_stack.push(temp);
        //while(!c_stack.empty())
        //{
        //    char c=c_stack.top();
        //    cout<<c<<endl;
        //    c_stack.pop();
        //}
        //cout<<"================="<<endl;
        //while(!v_stack.empty())
        //{
        //    int value =v_stack.top();
        //    cout<<value<<endl;
        //    v_stack.pop();
        //}
        while(!c_stack.empty())
        {
            char c=c_stack.top();
            c_stack.pop();
            int second=v_stack.top();
            v_stack.pop();
            int first=v_stack.top();
            v_stack.pop();
            int result=0;
            if(c=='+')
            {
                result=first+second;
            }else if(c=='-')
            {
                result=first-second;
            }else if(c=='*')
            {
                result=first*second;
            }else
            {
                result=first/second;
            }
            cout<<result<<endl;
            v_stack.push(result);
        }
        return v_stack.top();
    }

int main()
{
    string str="1+2*2";
    int result = calculate(str);
    cout<<result<<endl;
    return 0;
}
