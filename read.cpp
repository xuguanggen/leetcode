#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main()
{
    fstream fin;
    fin.open("x.txt",ios::in);
    string tmp;
    double num;
    while(getline(fin,tmp))
    {
        while(fin>>num)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}
