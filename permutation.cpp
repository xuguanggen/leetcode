#include <iostream>
#include <vector>
using namespace std;


vector< vector<int> > permutation(int n )
{
    vector< vector<int> > v;
    if (n==1)
    {
        vector<int> sub_v;
        sub_v.push_back(1);
        v.push_back(sub_v);
        return v;
    }else
    {
        vector< vector<int> > pre_v = permutation(n-1);
        vector< vector<int> >result;
        for(int i=0;i< pre_v.size();i++)
        {
            vector<int> sub_pre_v = pre_v[i];
            for(int position=0;position<n;position++)
            {
                vector<int> sub_result;
                if(position ==0)
                {
                    sub_result.push_back(n);
                    for(int idx =0;idx<sub_pre_v.size();idx++)
                    {
                        sub_result.push_back(sub_pre_v[idx]);
                    }
                    result.push_back(sub_result);
                }
                else if(position == n)
                {
                    for(int idx =0;idx<sub_pre_v.size();idx++)
                    {
                        sub_result.push_back(sub_pre_v[idx]);
                    }
                    sub_result.push_back(n);
                    result.push_back(sub_result);
                }else{
                    for(int idx=0;idx<position;idx++)
                    {
                        sub_result.push_back(sub_pre_v[idx]);
                    }
                    sub_result.push_back(n);
                    for(int idx=position;idx<sub_pre_v.size();idx++)
                        sub_result.push_back(sub_pre_v[idx]);
                    result.push_back(sub_result);
                }
            }
        }
        return result;
    }
}


int main()
{
    vector< vector<int> > result = permutation(4);
    for(int i=0;i<result.size();i++)
    {
        vector<int> sub_result = result[i];
        for(int j=0;j<sub_result.size();j++)
        {
            cout<<sub_result[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
