#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。*/
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++)
        {
            int tmp = nums[nums.size()-1];
            for (int j = nums.size() -1; j > 0; j--)
            {
                nums[j] = nums[j-1];
            }
            nums[0] = tmp;
        }
    }
};

class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> t = nums;
        for (int i = 0; i < nums.size(); ++i) {
            
            cout<<i<<" "<<(i + k) % nums.size()<<endl;

            nums[(i + k) % nums.size()] = t[i];
        }
    }
};

class Solution3 {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        for (int i = 0; i < n - k; ++i) {
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }
    }
};

class Solution4 {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) 
            return;
        int n = nums.size(), start = 0;   
        while (n && (k %= n)) {
            for (int i = 0; i < k; ++i) {
                swap(nums[i + start], nums[n - k + i + start]);
            }
            n -= k;
            start += k;
        }
    }
};

class Solution5 {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) 
            return;
        int start = 0, idx = 0, pre = 0, cur = nums[0], n = nums.size();
        for (int i = 0; i < n; ++i) {
            pre = cur;
            idx = (idx + k) % n;
            cur = nums[idx];
            nums[idx] = pre;
            if (idx == start) {
                idx = ++start;
                cur = nums[idx];
            }
        }
    }
};

int main()
{
    vector<int> nums{1,2,3,4,5,6,7};
    int k = 3;
    Solution4 s4;
    s4.rotate(nums,k);
    cout<<"--------------------"<<endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<endl;
    }
    
}
