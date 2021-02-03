#include <iostream>
#include <deque>
#include <vector>
#include <set>
using namespace std;
/*hard*/
class Solution {/*version 1*/
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int i = 0;
        vector<double> res;
        deque<int> Q;
        while (i<nums.size()){
            Q.push_back(nums[i]);
            if (Q.size() == k)
            {
                vector<int> tmp(Q.begin(),Q.end());
                sort(tmp.begin(),tmp.end());
                if(k%2 == 1)
                    res.push_back(tmp[k/2]);
                else
                    res.push_back(tmp[k/2]/2.0+tmp[k/2-1]/2.0);
                Q.pop_front();
            }
            i++;
        }
        return res;
    }
};

class Solutionv2 {/*version 1*/
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int i = 0;
        vector<double> res;
        deque<int> Q;
        while (i<nums.size()){
            Q.push_back(nums[i]);
            if (Q.size() == k)
            {
                multiset<double> ms(Q.begin(), Q.begin());
                auto mid = next(ms.begin(), k / 2);
                if(k%2 == 1)
                    res.push_back(*mid);
                else
                    res.push_back((*mid)/2.0+(*(--mid))/2.0);
                Q.pop_front();
                ms.clear();
            }
            i++;
        }
        return res;
    }
};
/*
    后来看到了史蒂芬大神的方法，原来是要用一个multiset集合，和一个指向最中间元素的iterator。
    我们首先将数组的前k个数组加入集合中，由于multiset自带排序功能，所以我们通过k/2能快速的找
    到指向最中间的数字的迭代器mid，如果k为奇数，那么mid指向的数字就是中位数；如果k为偶数，那么
    mid指向的数跟前面那个数求平均值就是中位数。
    
    当我们添加新的数字到集合中，multiset会根据新数
    字的大小加到正确的位置，然后我们看如果这个新加入的数字比之前的mid指向的数小，那么中位数肯定
    被拉低了，所以mid往前移动一个；再看如果要删掉的数小于等于mid指向的数(注意这里加等号是因为要
    删的数可能就是mid指向的数)，则mid向后移动一个。然后我们将滑动窗口最左边的数删掉，我们不能直
    接根据值来用erase来删数字，因为这样有可能删掉多个相同的数字，而是应该用lower_bound来找到
    第一个不小于目标值的数，通过iterator来删掉确定的一个数字.
*/
class Solution2 {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<double> ms(nums.begin(), nums.begin() + k);
        auto mid = next(ms.begin(), k /  2);
        for (int i = k; ; ++i) {
            res.push_back((*mid + *prev(mid,  1 - k % 2)) / 2);        
            if (i == nums.size()) 
                return res;
            ms.insert(nums[i]);
            if (nums[i] < *mid) 
                --mid;
            if (nums[i - k] <= *mid)//要删掉的数字
                ++mid;
            ms.erase(ms.lower_bound(nums[i - k]));
        }
    }
};

class SolutionX {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<double> st;
        for (int i = 0; i < nums.size(); ++i) {
            if (st.size() >= k) 
                st.erase(st.find(nums[i - k]));
            st.insert(nums[i]);
            if (i >= k - 1) {
                auto mid = st.begin();
                std::advance(mid, k / 2);
                res.push_back((*mid + *prev(mid, (1 - k % 2))) / 2);
            }
        }
        return res;
    }
};

class Solution3 {/*求最大值*/
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int i = 0;
        vector<double> res;
        deque<int> Q;
        for(int i=0;i<nums.size();i++)
        {
            while(!Q.empty() && nums[i] > nums[Q.back()])
            {
                Q.pop_back();
            }
            Q.push_back(i);
            if (Q.front() == i - k)
            {
                Q.pop_front();
            }
            if(i >=k-1)
                res.push_back(nums[Q.front()]);
        }
        return res;
    }
};

int main()
{
    vector<int>nums{};
    int k = 5463;
    Solution so;
    vector<double> res = so.medianSlidingWindow(nums,k);
    
}