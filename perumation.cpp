# include <iostream>
# include <vector>
# include <sstream>
using namespace std;

    string int2str(const int &int_temp)  
    {  
        stringstream stream;  
        stream<<int_temp;  
        string string_temp=stream.str(); 
        return string_temp;
    }  
    
    
    bool compare(vector<int>v1,vector<int>v2)
{
    int len=v1.size();
    for(int i=0;i<len;i++)
    {
        if(v1[i]<v2[i])
        {
            return true;
        }
        if(v1[i]>v2[i])
        {
            return false;
        }
    }
    return true;
}
void swap(vector<int> &v1,vector<int> &v2)
{
    int len=v1.size();
    for(int i=0;i<len;i++)
    {
        int temp= v1[i];
        v1[i]= v2[i];
        v2[i]=temp;
    }
}

void sort(vector<vector<int> >&v)
{
    int i=0,j=0;
    for(i=0;i<v.size()-1;i++)
    {
        int index=i;
        vector<int> min= v[i];
        for(j=i+1;j<v.size();j++)
        {
            if(compare(v[j],min))
            {
                min=v[j];
                index=j;
            }
        }
        swap(v[index],v[i]);
    }
}

vector<vector<int> > function(int n)
{
    if(n==1)
    {
        vector<int> temp;
        temp.push_back(1);
        vector<vector<int> >v;
        v.push_back(temp);
        return v;
    }else
    {
        vector<vector<int> > v;
        vector<vector<int> > lastResult= function(n-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<lastResult.size();j++)
            {
                vector<int> temp=lastResult[j];
                vector<int> newtemp;
                for(int k=0;k<i;k++)
                {
                    newtemp.push_back(temp[k]);
                }
                newtemp.push_back(n);
                for(int k=i;k<temp.size();k++)
                {
                    newtemp.push_back(temp[k]);
                }
                v.push_back(newtemp);
            }
        }
        sort(v);
        return v;

    }
}

    string getPermutation(int n, int k) {
        vector<vector<int> > v= function(n);
        vector<int> result= v[k];
        string value="";
        for(int i=0;i<result.size();i++)
        {
            value=value+int2str(result[i]);
        }
        return value;
    }


int main()
{
   // int n=4;
   // vector<vector<int> >v;
   // v= function(4);
   // for(int i=0;i<v.size();i++)
   // {
   //     for(int j=0;j<v[i].size();j++)
   //     {
   //         cout<<v[i][j]<<" ";
   //     }
   //     cout<<endl;
   // }
    cout<<getPermutation(4,2)<<endl;
    return 0;
}
