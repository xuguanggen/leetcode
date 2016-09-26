#include <iostream>
#include <vector>
using namespace std;
int maxProduct(vector<int>& nums) {
    if(nums.empty())
        return 0;
    int len=nums.size();
    int c[len][len]={1};
    int i=0,j=0;
    int maxValue=1;
    for(i=0;i<len;i++)
    {
        c[i][i]=nums[i];
        maxValue=max(maxValue,nums[i]);
    }
    for(i=0;i<len-1;i++){
        c[i][i+1]=nums[i]*nums[i+1];
        maxValue=max(maxValue,c[i][i+1]);
    }
    int cur_len=3;
    for(cur_len=3;cur_len<=len;cur_len++)
    {
        for(j=0;j<=len-cur_len+1;j++)
        {
            c[j][j+cur_len-1]=c[j+1][j+cur_len-2]*nums[j]*nums[j+cur_len-1];
            maxValue=max(maxValue,c[j][j+cur_len-1]);
        }
    }
    return maxValue;
}
int main()
{
	vector<int>v;
	v.push_back(2);
	v.push_back(-3);
	v.push_back(-2);
	v.push_back(4);
    v.push_back(-4);
	int result=maxProduct(v);
	cout<<result<<endl;
	return 0;
}
