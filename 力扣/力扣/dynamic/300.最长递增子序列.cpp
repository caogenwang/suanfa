#include <iostream>
#include <vector>

using namespace std;
/*dp[i]以nums[i]为结尾的最长上升子序列*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i-1])
            {
                dp[i] = dp[i-1]+1; 
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }
        return dp[nums.size()];
    }
};

/*dp[i]以nums[i]为结尾的最长上升子序列,序列不一定是连续的*/
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    cout<<dp[i]<<" ";
                }
            }
            res = max(res, dp[i]);
        }
        cout<<endl;
        return res;
    }
};

class Solution3 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> stack;
        stack.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > stack.back())
            {
                stack.push_back(nums[i]);
            }
            else
            {
                for (int j = 0; j < stack.size(); j++)
                {
                    if (stack[j] >= nums[i]){//替换第一个大于等于它的位置的数
		    			stack[j] = nums[i];
		    			break;
		    		}
                }
                   
            }
        }
        for (int i = 0; i < stack.size(); i++)
        {
            cout<<stack[i]<<endl;
        }
        
        return stack.size();
    }
};
/*
    下面来看一种优化时间复杂度到 O(nlgn) 的解法，这里用到了二分查找法，所以才能加快运行时间哇。
    思路是，先建立一个数组 ends，把首元素放进去，然后比较之后的元素，如果遍历到的新元素比 ends 
    数组中的首元素小的话，替换首元素为此新元素，如果遍历到的新元素比 ends 数组中的末尾元素还大的话，
    将此新元素添加到 ends 数组末尾(注意不覆盖原末尾元素)。如果遍历到的新元素比 ends 数组首元素大，
    比尾元素小时，此时用二分查找法找到第一个不小于此新元素的位置，覆盖掉位置的原来的数字，
    以此类推直至遍历完整个 nums 数组，此时 ends 数组的长度就是要求的LIS的长度，特别注意的是 ends 
    数组的值可能不是一个真实的 LIS，比如若输入数组 nums 为 {4, 2， 4， 5， 3， 7}，
    那么算完后的 ends 数组为 {2， 3， 5， 7}，可以发现它不是一个原数组的 LIS，只是长度相等而已，
    千万要注意这点
*/

class Solution4 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> ends{nums[0]};
        for (auto a : nums) {
            if (a < ends[0]) 
                ends[0] = a;
            else if (a > ends.back()) 
                ends.push_back(a);
            else 
            {
                int left = 0, right = ends.size();
                while (left < right) 
                {
                    int mid = left + (right - left) / 2;
                    if (ends[mid] < a) 
                        left = mid + 1;
                    else 
                        right = mid;
                }
                ends[right] = a;
            }
        }
        return ends.size();
    }
};


/*
    我们来看一种思路更清晰的二分查找法，跟上面那种方法很类似，思路是先建立一个空的 dp 数组，
    然后开始遍历原数组，对于每一个遍历到的数字，用二分查找法在 dp 数组找第一个不小于它的数字，
    如果这个数字不存在，那么直接在 dp 数组后面加上遍历到的数字，如果存在，
    则将这个数字更新为当前遍历到的数字，
    最后返回 dp 数组的长度即可，注意的是，跟上面的方法一样，特别注意的是 dp 数组的值可能不是一个真实的 
    LIS
*/
class Solution5 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); ++i) 
        {
            int left = 0, right = dp.size();
            while (left < right) 
            {
                int mid = left + (right - left) / 2;
                if (dp[mid] < nums[i]) 
                    left = mid + 1;
                else 
                    right = mid;
            }
            if (right >= dp.size()) 
                dp.push_back(nums[i]);
            else 
                dp[right] = nums[i];
        }
        return dp.size();
    }
};

/*
    下面来看两种比较 tricky 的解法，利用到了 C++ 中 STL 的 lower_bound 函数，lower_bound 
    返回数组中第一个不小于指定值的元素，跟上面的算法类似，还需要一个一维数组v，然后对于遍历到的 nums 
    中每一个元素，找其 lower_bound，如果没有 lower_bound，说明新元素比一维数组的尾元素还要大，
    直接添加到数组v中，跟解法二的思路相同了。如果有 lower_bound，说明新元素不是最大的，将其 lower_bound 
    替换为新元素，这个过程跟算法二的二分查找法的部分实现相同功能，最后也是返回数组v的长度，注意数组v也不一定
    是真实的 LIS
*/
class Solution6 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for (auto a : nums) {
            auto it = lower_bound(v.begin(), v.end(), a);
            if (it == v.end()) 
                v.push_back(a);
            else 
                *it = a;
        }
　　　　　return v.size();
    }
};

class Solution7 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for (auto a : nums) {
            if (find(v.begin(), v.end(), a) != v.end()) 
                continue;
            auto it = upper_bound(v.begin(), v.end(), a);
            if (it == v.end()) 
                v.push_back(a);
            else 
                *it = a;
        }
        return v.size();
    }
};


int main()
{
    int test[] = {1, 3, 2, 3, 0, 4};
	std::vector<int> nums;
	for (int i = 0; i < 6; i++){
		nums.push_back(test[i]);
	}
	Solution7 s;
    int len = s.lengthOfLIS(nums);
    cout<<len<<endl;
}
