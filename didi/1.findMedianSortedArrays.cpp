#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

float findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int i = 0;
    int j = 0;
    vector<int> arr;
    while (i<nums1.size() && j<nums2.size())
    {
        if (nums1[i] >= nums2[j])
        {
            arr.push_back(nums2[j++]);
        }
        else
        {
            arr.push_back(nums1[i++]);
        }
    }
    while (i<nums1.size())
        arr.push_back(nums1[i++]);
    while (j<nums2.size())
        arr.push_back(nums2[j++]);
    for (int m = 0; m < arr.size(); m++)
    {
        // cout<<arr[m]<<endl;
    }
    int k = arr.size() / 2;
    return k?arr[k]:(float)(arr[k-1]+arr[k])/2.0;
}

/*
采用非归并排序是m+n,
给定两个大小为m，n的有序数组nums1和nums2，
找出这两个有序数组的中位数，要求时间复杂度为O(log(m+n)),log基本要二分查找
那么对谁二分呢，数组么？其实要对K二分，意思是需要分别在 nums1 和 nums2 中查找第 K/2 个元素
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (i >= nums1.size()) return nums2[j + k - 1];
        if (j >= nums2.size()) return nums1[i + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        if (midVal1 < midVal2) {//小的那个往由移动。
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        } else {
            return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1,3,5,7,9};
    vector<int> nums2 = {2,4,6,8,10,11};
    Solution s;
    double res = s.findMedianSortedArrays(nums1,nums2);
    cout<<res<<endl;
    return 0;
}
