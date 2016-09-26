#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
    string char2str(char ch)
{
    string str;
    stringstream stream;
    stream<<ch;
    str=stream.str();
    return str;
}
    void function(string& str,vector<string>&dic,int& len,int &position,vector<string>&result)
    {
        if(position==len)
        {
            return;
        }else{
            char ch=str[position];
            string value = dic[ch-'2'];
            if(position==0)
            {
                for(int i=0;i<value.length();i++)
                {
                    result.push_back(char2str(value[i]));
                }
                position++;
                function(str,dic,len,position,result);
            }else
            {
                int n=result.size();
                vector<string> part_result;
                for(int i=0;i<n;i++)
                {
                    string temp=result[i];
                    for(int j=0;j<value.length();j++)
                    {
                        part_result.push_back(temp+value[j]);
                    }
                }
                result.clear();
                for(int i=0;i<part_result.size();i++)
                {
                    result.push_back(part_result[i]);
                }
                position++;
                function(str,dic,len,position,result);
            }
        }
    }
        
    vector<string> letterCombinations(string digits) {
        vector<string> strs;
        strs.push_back("abc"); //2
        strs.push_back("def");
        strs.push_back("ghi");
        strs.push_back("jkl");
        strs.push_back("mno");
        strs.push_back("pqrs");
        strs.push_back("tuv");
        strs.push_back("wxyz");//9
        
        vector<string>result;
        if(digits==""||digits.length()==0)
            return result;
        int len=digits.length();
        int position=0;
        function(digits,strs, len,position,result);
        return result;
    }

   int main()
   {
      string str;
      cin>>str;
   //   char ch='a';
   	// cout<<string(ch)<<endl;
      vector<string> result = letterCombinations(str);
   	 for(int i=0;i<result.size();i++)
   	 {
   	 	cout<<result[i]<<endl;
   	 }
   	 cout<<endl;
   	 return 0;
   }
