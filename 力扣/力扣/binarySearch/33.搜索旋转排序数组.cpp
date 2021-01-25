#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {/*通不过*/
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int left = i;
        int right = nums.size() - 1;
        int mid = (right + left)/2;
        while (left <= right)
        {
            mid = (right + left)/2;
            cout<<left<<" "<<right<<" "<<mid<<endl;
            if (target == nums[mid])
            {
                return mid;
            }
            else if(target < nums[mid])
            {
                if(target == nums[left])
                {
                    return left;
                }
               else if(target < nums[left])
                {
                    left = mid + 1;
                }
                else
                {
                    right = max(mid-1,0);
                }
            }
            else
            {
                if(target == nums[right])
                {
                    return right;
                }
                else if(target < nums[right])
                {
                    left = mid+1;
                }
                else
                {
                    right = max(mid-1,0);
                }
                
            }            
        }
        return -1;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) 
                return mid;
            if (nums[mid] < nums[right])//先判断mid在哪个序列，在判断target在哪个序列
            {
                if (nums[mid] < target && nums[right] >= target) 
                    left = mid + 1;
                else 
                    right = mid - 1;
            } 
            else 
            {
                if (nums[left] <= target && nums[mid] > target) 
                    right = mid - 1;
                else 
                    left = mid + 1;
            }
        }
        return -1;
    }
};


/*

*/
int search(vector<int> &nums,int target)
{
    int size = (int)nums.size();
    int left = 0;
    int right = size - 1;
    int mid = 0;
    while (left <= right){
       int mid = left + (right - left) / 2;
        if (nums[mid] == target) 
            return mid;
        else if(nums[mid] < nums[right]){
            if(target > nums[mid] && target )
                left = mid + 1;
            else
                right = mid - 1;
                
            
        }
        else{

        }
    }
    return -1;
}


int main()
{
    vector<int>nums{4,5,6,7,0,1,2};
    // vector<int>nums{1,3};
    int target = 0;
    Solution s;
    int res = search(nums,target);
    cout<<res<<endl;
}