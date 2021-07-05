#include <iostream>
#include<vector>
using namespace std;

/*
    输入：nums = [1,2,3]
    输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> item;
        result.push_back(item);
        helper(0,nums,item,result);
        return result;
    }
    void helper(int i,vector<int>& nums,vector<int>& item,vector<vector<int> > &result){
        if (i >= nums.size()){
            return ;
        }
        item.push_back(nums[i]);
        result.push_back(item);
        helper(i+1,nums,item,result);
        item.pop_back();
        helper(i+1,nums,item,result);
    }
};

int main(){

}