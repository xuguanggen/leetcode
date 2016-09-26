#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <strstream>
using namespace std;
 string reverseVowels(string s) {
         set<char> st;
         st.insert('a');
         st.insert('e');
         st.insert('i');
         st.insert('o');
         st.insert('u');
         int len=s.length();
         int i=0,j=0;
         int pre_ch=-1;
         int cur_ch;
         for(i=0;i<len;i++)
         {
             if(st.count(tolower(s[i])))
             {
                 if(pre_ch==-1)
                 {
                     pre_ch=i;
                 }else
                 {
                     char ch=s[pre_ch];
                     s[pre_ch]=s[i];
                     s[i]=ch;
                     pre_ch=i;
                 }
             }
         }
         return s;
    }
int main()
{
   // string str="leetcode";
   // char ch='r';
   // cout<<str+ch<<endl;
   // cout<<reverseVowels(str)<<endl;
   cout<<1 ^ 10<<endl;
    return 0;
}
