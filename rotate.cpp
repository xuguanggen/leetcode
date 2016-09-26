#include<iostream>
#include<vector>
using namespace std;
   void function(vector<int>&nums,int start,int end)
    {
        int i=start;
        int j=end;
        while(i<j)
        {
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        function(nums,0,k);
        function(nums,k+1,nums.size()-1);
        function(nums,0,nums.size()-1);
    }

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    rotate(v,3);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
