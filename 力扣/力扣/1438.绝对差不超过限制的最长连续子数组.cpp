#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <multiset>
#include <queue>
using namespace std;

class Solution1 {
public:
    int longestSubarray(vector<int>& nums, int limit) {

    }
};
class Solution2 {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int ans = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            s.insert(nums[j]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[i]));
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
class Solution2 {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> m;
        int ans = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            m[nums[j]]++;
            while (m.rbegin()->first - m.begin()->first > limit) {
                m[nums[i]]--;
                if (m[nums[i]] == 0) {
                    m.erase(nums[i]);
                }
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }

};

int main()
{
    vector<int>nums{1,5,6,7,8,10,6,5,6};
    int limit = 4;
    Solution so;
    int res = so.longestSubarray(nums,limit);
    cout<<res<<endl;
}