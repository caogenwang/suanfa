#include <stdio.h>

#include <vector>
using namespace std;
// class Solution {
// public:
//     int search(std::vector<int>& nums, int target) {
//     	int begin = 0;
// 		int end = nums.size() - 1;
// 		while(begin <= end){
// 			int mid = (begin + end) / 2;
// 			if (target == nums[mid]){
// 				return mid;
// 			}
// 			else if (target < nums[mid]){
// 				if (nums[begin] < nums[mid]){
// 					if (target >= nums[begin]){
// 						end = mid - 1;
// 					}
// 					else{
// 						begin = mid + 1;
// 					}
// 				}
// 				else if (nums[begin] > nums[mid]){
// 					end = mid -1;
// 				}
// 				else if (nums[begin] == nums[mid]){
// 					begin = mid + 1;
// 				}
// 			}
// 			else if (target > nums[mid]){
// 				if (nums[begin] < nums[mid]){
// 					begin = mid + 1;
// 				}
// 				else if (nums[begin] > nums[mid]){
// 					if (target >= nums[begin]){
// 						end = mid - 1;
// 					}
// 					else{
// 						begin = mid + 1;
// 					}
// 				}
// 				else if (nums[begin] == nums[mid]){
// 					begin = mid + 1;
// 				}
// 			}
// 		}
// 		return -1;
//     }
// };

class Solution2{
	public:
		int search(std::vector<int> &nums,int target)
		{
			int point = dispatchPoint(nums,target);
			
			if (target == nums[point])
			{
				return point;
			}
			else if(target > nums[point])
			{
				std::vector<int> datas(nums.begin(),nums.begin()+point);
				return binary_search(datas,target);
			}
			else
			{
				std::vector<int> datas(nums.begin()+point,nums.end());
				return binary_search(datas,target);
			}
		}
		int dispatchPoint(std::vector<int> &nums,int target)
		{
			if (target == nums[0])
			{
				return 0;
			}
			
			for (int i = 1; i < nums.size(); i++)
			{
				if (nums[i] < nums[i-1])
				{
					return i;
				}	
			}
			return 0;
		}
		int binary_search(std::vector<int> &nums,int target)
		{
			int begin = 0;
			int end = nums.size();
			while (begin < end)
			{
				int mid = (begin + end) / 2;
				if (target == nums[mid])
				{
					return mid;
				}
				else if(target > nums[mid])
				{
					begin = mid + 1;
				}
				else 
				{
					end = mid - 1;
				}
			}
			return -1;
		}
};


int main(){
	int test[] = {9, 12, 15, 20, 1, 3, 6, 7};
	std::vector<int> nums;
	Solution2 solve;
	for (int i = 0; i < 8; i++){
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 22; i++){
		printf("%d : %d\n", i, solve.search(nums, i));
	}
	return 0;
}
