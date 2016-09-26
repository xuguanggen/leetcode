#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty())
    {
        return NULL;
    }
    string first_str=strs[0];
    int min_len=first_str.length();
    int i=0;
    
    for(i=0;i<min_len;i++)
    {
        char c=first_str[i];
        for(int j=1;j<strs.size();j++)
        {
          string str=strs[j];
          if(str[i]!=c)
          {
              return first_str.substr(0,i);
          }
            
        }
    }
    return "";
}

int main()
{
    vector<string> v;
    v.push_back("aabcd");
    v.push_back("aabcefdgg");
    v.push_back("aabcrrrr");
    string str=longestCommonPrefix(v);
    cout<<str<<endl;
    return 0;
}
