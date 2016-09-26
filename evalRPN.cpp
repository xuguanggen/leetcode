#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;
bool IsDigit(string str)
{
    if(str!="+"&&str!="-"&&str!="*"&&str!="/")
        return true;
    else
        return false;
    return false;
}
int str2int(string str)
{
    stringstream ss;
    ss<<str;
    int value;
    ss>>value;
    return value;
}
int evalRPN(vector<string>& tokens) {
    if(tokens.empty())
        return 0;
    stack<int>s;
    int i=0;
    for(i=0;i<tokens.size();i++)
    {
        string str=tokens[i];
        if(IsDigit(str))
        {
            s.push(str2int(str));
        }else
        {
            int second= s.top();
            s.pop();
            int first = s.top();
            s.pop();
            if(str=="+")
            {
                s.push(first+second);
            }
            if(str=="-")
            {
                s.push(first-second);
            }
            if(str=="*")
            {
                s.push(first*second);
            }
            if(str=="/")
            {
                s.push(first/second);
            }
        }
    }
    
    return s.top();
}

int main()
{
	vector<string> tokens;
    tokens.push_back("2");
    tokens.push_back("1");
    tokens.push_back("+");
    tokens.push_back("3");
    tokens.push_back("*");
    int result = evalRPN(tokens);
    cout<<result<<endl;
	return 0;
}
