#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    输入：nums = [2,7,11,15], target = 9
    输出：[0,1]
    解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1]
*/
//算法的时间复杂度是 O(n^2)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sum;
        for (int i = 0; i < nums.size(); i++)
        {
            for ( int j = i+1; j < nums.size(); j++)
            {
                if (nums[i]+nums[j] == target)
                {
                    sum.push_back(i);
                    sum.push_back(j);
                }
            }            
        }
        return sum;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> sum;
        for (int i = 0; i < nums.size(); i++)
        {
            m.insert(std::pair<int,int>(nums[i],i));
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int left = target - nums[i];
            if (m.find(left) != m.end())
            {
                sum.push_back(i);
                sum.push_back(m[left]);
                break;
            }
        }
        return sum;
    }
};

class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int t = target - nums[i];
            if (m.count(t) && m[t] != i) {
                res.push_back(i);
                res.push_back(m[t]);
                break;
            }
        }
        return res;
    }
};


int main()
{
    vector<int> nums{2,7,11,15};
    int sum = 9;

    Solution2 s2;
    vector<int> vec = s2.twoSum(nums,sum);
    for (auto  i: vec)
        cout<<i<<endl;
    
}