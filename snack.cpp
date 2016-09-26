#include<iostream>
#include<vector>
using namespace std;


void print(vector<vector<int> >v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int> > generate(int n)
{
    vector<vector<int> >v(n,vector<int>(n,0));
    int limit = n*n;
    int index=1;
    int t=0,b=n-1,l=0,r=n-1;
    while(index<=limit)
    {
        for(int i=l;i<=r;i++)
        {
            v[t][i]=index++;
        }
        t++;
        for(int i=t;i<=b;i++)
        {
            v[i][r]=index++;
        }
        r--;
        for(int i=r;i>=l;i--)
        {
            v[b][i]=index++;
        }
        b--;
        for(int i=b;i>=t;i--)
        {
            v[i][l]=index++;
        }
        l++;
    }
    print(v);
    return v;
}

int main()
{
    int n=4;
    cin>>n;
    generate(n);
    return 0;
}
