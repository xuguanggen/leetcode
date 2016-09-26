# include <iostream>
# include <cstdlib>
# include <stdlib.h>
# include <vector>
# include <cstring>
# include <string>
# include <sstream>
# include <fstream>
using namespace std;
int main()
{
    //ifstream in("x.txt");
    //string s;
    //while(getline(in,s))    
    //{
    //    cout<<s<<endl;
    //}
	//string s="12.134545";
	//cout<<atof(s.c_str())<<endl;
	//const char*p=s.c_str();
	//double d;
	//sscanf(p,"%f",&d);
	//cout<<d<<endl;
	//double d;
	//stringstream ss;
	//ss<<s;
	//ss>>d;
	//cout<<d<<endl;
	//cout<<0.2/10000<<endl;
	//char str[]="123.312321";
	//double a;
	//sscanf(str,"%lf",&a);
	//cout<<a<<endl;
	double c=strtod("32.123456",NULL);
	cout<<c<<endl;

	istringstream s1("32.123456");
	s1>>c;
	cout<<c<<endl;

	sscanf("32.123456","%f",&c);
	cout<<c<<endl;
	char ch[]="32.123456";
	double t=atof(ch);
	cout<<t<<endl;
    return 0;
}
