#include <iostream>
#include <string>
#include <vector>
using namespace std;
int longestLength(string &str)
{
    int maxlen=1;
    int begin=0;
    int len=str.length();
    bool table[len][len];
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
            table[i][j]=false;
    }
    for(int i=0;i<len;i++)
    {
        table[i][i]=true;
    }
    for(int i=0;i<len-1;i++)
    {
        if(str[i]==str[i+1])
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
            if(str[i]==str[i+cur_len-1]&&table[i+1][i+cur_len-2])
            {
                begin=i;
                maxlen=cur_len;
                table[i][i+cur_len-1]=true;
            }
        }
    }
    return maxlen;
}



int main()
{
    int n;
    cin>>n;
    vector<string>v;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        v.push_back(str);
    }
    for(int i=0;i<n;i++)
    {
        cout<<longestLength(v[i])<<endl;
    }
    return 0;
}