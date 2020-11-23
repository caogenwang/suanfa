#include <vector>
#include <iostream>
using namespace std;


void generate(int i,vector<int> &nums,vector<int> &item,vector<vector<int> > &result)
{
    if(i>=nums.size())
        return;
    item.push_back(nums[i]);
    result.push_back(item);
    generate(i+1,nums,item,result);
    item.pop_back();
    generate(i+1,nums,item,result);
}

vector<vector<int> > subsets(vector<int> &nums)
{
    vector<vector<int> > result;
    if (nums.size() == 0)
    {
        return result;
    }
    vector<int> item;
    result.push_back(item);
    generate(0,nums,item,result);
    return result;
}
/*
1 
1 2 
1 2 3 
1 2 3 4 
1 2 4 
1 3 
1 3 4 
1 4 
2 
2 3 
2 3 4 
2 4 
3 
3 4 
4 
*/
void generate2(int i,vector<int> &nums,vector<int> &item,vector<vector<int> > &result,int target,int sum)
{
    if(i>=nums.size() || sum > target)
        return;
    item.push_back(nums[i]);
    sum+=nums[i];
    if(sum == target)
    {
        result.push_back(item);
    }
    generate2(i+1,nums,item,result,target,sum);
    sum-=nums[i];
    item.pop_back();
    generate2(i+1,nums,item,result,target,sum);
}

vector<vector<int> > subsets2(vector<int> &nums,int target)
{
    vector<vector<int> > result;
    if (nums.size() == 0)
    {
        return result;
    }
    vector<int> item;
    int sum = 0;
    generate2(0,nums,item,result,target,sum);
    return result;
}

int main(int argc,char**argv)
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<vector<int> > result = subsets2(v,5);
    for (size_t i = 0; i < result.size(); i++)
    {
        vector<int> temp = result[i];
        for (size_t j = 0; j < temp.size(); j++)
        {
            cout<<temp[j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}