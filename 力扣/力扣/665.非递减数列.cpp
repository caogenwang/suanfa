#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        multiset<int> s(nums.begin(),nums.begin()+1);
        multiset<int>::iterator it;
        int i = 1;
        int k = 1;
        while (i < nums.size()){
            if (k > 0){
                cout<<"1"<<endl;
                it = prev(s.end(),1);
                cout<<(*it)<<endl;
            }
            else{
                cout<<"2"<<endl;
                it = prev(s.end(),2);
                cout<<(*it)<<endl;
            }
            cout<<nums[i]<<" "<<(*it)<<endl;
            if (nums[i] < (*it)){
                k --;
                if (s.size()>1)
                    i --;
            }
            cout<<"k:"<<k<<endl;
            if (k<0)
                return false;
            s.insert(nums[i]);
            i ++;
        }
        return true;
    }
};

class Solution2 {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i-1])
            {
                if(cnt <= 0)
                    return false;
                if (i == 1 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
                cnt --;
            }
        }
        return true;
    }
};

class Solution3 {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 1, n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                if (cnt == 0) 
                    return false;
                if (i == 1 || nums[i] >= nums[i - 2]) 
                    nums[i - 1] = nums[i];
                else 
                    nums[i] = nums[i - 1];
                --cnt;
            } 
        }
        return true;
    }
};

int main()
{
    vector<int> nums{3,4,2,3};
    Solution2 su;
    bool res = su.checkPossibility(nums);
    cout<<res<<endl;
}