#include<iostream>
#include<math.h>
using namespace std;

void IsPerfectSquare(int n)
{
    double s=sqrt(n);
    cout<<s<<endl;
    int value=int(s);
    cout<<value<<endl;
    //if(s-int(s)>-0.00001&&(s-int(s))<0.00001)
    //    return true;
    //return false;
}


int main()
{
    int n;
    cin>>n;
    IsPerfectSquare(n);
    //bool result=IsPerfectSquare(n);
    //
    //cout<<result<<endl;
    return 0;

}
