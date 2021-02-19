#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0, zero = 0, left = 0, k = K;
        for (int right = 0; right < A.size(); ++right) {
            if (A[right] == 0) ++zero;
            while (zero > k) {
                if (A[left++] == 0) --zero;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main()
{
    vector<int> nums{1,1,1,0,0,0,1,1,1,1,0};
    int K = 2;
    Solution so;
    int res = so.longestOnes(nums,K);
    cout<<res<<endl;
}