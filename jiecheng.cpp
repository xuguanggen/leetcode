#include<iostream>
using namespace std;

void method_1(int &n)
{
    int ret = 0;
    int j=1;
    for (int i=1;i<= n;i++)
    {
        j = j*i;
        while(j%5==0)
        {
            ret++;
            j/=5;
        }
    }
    cout<<ret<<endl;
}

int main()
{
    int n;
    cin>>n;
    method_1(n);
    return 0;
}
