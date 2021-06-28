#include <iostream>
#include <vector>
using namespace std;

/*
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> rot1(nums.begin()+k+1,nums.begin()+ nums.size());
        vector<int> rot2(nums.begin(),nums.begin()+k+1);
        for (int i = 0; i < rot1.size(); i++)
            nums[i] = rot1[i];
        for (int j = 0; j < rot2.size(); j++)
            nums[rot1.size()+j] = rot2[j];
    }
};

class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newArr(n);
        for (int i = 0; i < n; ++i) {
            newArr[(i + k) % n] = nums[i];
        }
        nums.assign(newArr.begin(), newArr.end());
    }
};

/*

    1 2 3 4 5 6 7
    4 3 2 1 5 6 7
    4 3 2 1 7 6 5
    5 6 7 1 2 3 4

*/
class Solution3 {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

class Solution4 {
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


/*
    1 2 3 4 5 6 7
    5 2 3 4 1 6 7
    5 6 3 4 1 2 7
    5 6 7 4 1 2 3
    5 6 7 1 4 2 3
    5 6 7 1 2 4 3
    5 6 7 1 2 3 4
*/
class Solution5 {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
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

int main(){
    Solution4 s;
    vector<int> nums{1,2,3,4,5,6,7};
    int k = 3;
    s.rotate(nums,k);
    for (int m : nums)
        cout<<m<<" ";
    cout<<endl;
    return 0;
}