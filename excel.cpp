#include<iostream>
#include<vector>
#include<string>
using namespace std;

 string convertToTitle(int n) {
        if(n<=0)
        {
            return "";
        }
        int *value = new int [26];
        char * zimu = new char [26];
        int i=0;
        for(i=0;i<26;i++)
        {
            value[i] = i+1;
            zimu[i]= 'A'+ i;
        }
        vector<char> result;
        while(n>0)
        {
            int mod=n%27;
            if(mod==0)
                result.push_back('A');
            else
                result.push_back(zimu[mod]);
        
            n=n/27;
        }
        string r="";
        for(i=result.size()-1;i>=0;i--)
        {
            r+=result[i];
        }
        return r;
    }

int main()
{
    cout<<convertToTitle(29)<<endl;
    return 0;
}
