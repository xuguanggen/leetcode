#include <iostream>
#include <limits.h>
using namespace std;


int cut_rod(int *p,int n)
{
    if(n==0)
        return 0;
    int q=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        q=max(q,p[i-1]+cut_rod(p,n-i));
    }
    return q;
}

int bottom_up_cut_rod(int *p,int n)
{
    int *r=new int [n+1];
    r[0]=0;
    for(int j=1;j<=n;j++)
    {
        int q=INT_MIN;
        for(int i=1;i<=j;i++)
        {
            q=max(q,p[i-1]+r[j-i]);
        }
        r[j]=q;
    }
    return r[n];
}

int main()
{
    int P[]={1,5,8,9,10,17,17,20,24,30};
    int n;
    cin>>n;
    cout<<bottom_up_cut_rod(P,n)<<endl;
    return 0;
}
