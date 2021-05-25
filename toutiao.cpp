#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> combine(vector<int> &nums1,vector<int> &nums2){
        int len1 = nums1.size(),len2 = nums2.size(),i=0,j=0;
        vector<int> res;
        while (i<len1 && j<len2){
            if(nums1[i] < nums2[j])
                res.push_back(nums1[i++]);
            else if(nums1[i] > nums2[j])
                res.push_back(nums2[j++]);
            else{
                res.push_back(nums1[i++]);
                j++;
            }
        }
        while (i<len1)
            res.push_back(nums1[i++]);
        while (j<len2)
            res.push_back(nums2[j++]);
        
        return res;
    }
};
int main(){
    vector<int> nums1{1,4,6,8,10,12};
    vector<int> nums2{2,3,6,8,9,11};
    Solution s;
    vector<int> nums = s.combine(nums1,nums2);
    for(int i:nums)
        cout<<i<<endl;
}