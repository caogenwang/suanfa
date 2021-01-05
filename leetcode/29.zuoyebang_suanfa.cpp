#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
//在旋转数组中二分查找，不同于zuoyebang的V型数据。旋转数组的有个特点，旋转点的左边的数总是大于旋转点右边的数
int search(vector<int>& nums, int target) {
    int len=nums.size();
    int low=0,high=len-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target)
        {
            return mid;
        }

        if(nums[mid]<nums[low])
        {
            if(nums[mid]<target&&target<=nums[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        else if(nums[mid]>nums[high])
        {
            if(nums[mid]>target&&target>=nums[low])
            {
                high=mid-1;
            }else
            {
                low=mid+1;
            }
        }
        else{
            if(nums[mid]<target)
            {
                low=mid+1;
            }else
            {
                high=mid-1;
            }
        }
    }
    return -1;
}

int V_search(vector<int>& nums)
{
    int len=nums.size();
    int low=0,high=len-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]-nums[mid-1] < 0 && nums[mid]-nums[mid+1]<0)
        {
            return nums[mid];
        }
        if(nums[mid]-nums[mid-1] < 0)
        {
            low = mid + 1;
        }
        else if(nums[mid]-nums[mid-1] > 0)
        {
            high = mid - 1;
        }
    }
    
    return -1;
}

// int main(int argc,char**argv)
// {
    
//     vector<int> nums = {15,13,12,11,10,8,7,6,5,4,1,2,3,5,7,8,7,10,11,15};
//     printf("%d\n",V_search(nums));
    
// }

int main(int argc,char**argv)
{
    if (argc>1)
    {
        vector<int> nums = {4,5,6,7,8,9,1,2,3};
        int  target = 3;
        printf("%d\n",search(nums,target));
    }
    else
    {
        vector<int> nums = {8,7,6,5,4,1,2,3};
        int  target = 3;
        printf("%d\n",V_search(nums));
    }
    
}