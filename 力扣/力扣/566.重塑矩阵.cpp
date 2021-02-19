#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
        if(r*c != nums[0].size() * nums.size())
            return nums;
        vector<int> t;
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums[i].size(); j++)
                t.push_back(nums[i][j]);
        vector<vector<int> > res;
        for (int i = 0; i < r; i++)
        {
            vector<int> tmp(t.begin()+i*c,t.begin()+i*c+c);
            res.push_back(tmp);
        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c) return nums;
        vector<vector<int> > res(r, vector<int>(c));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int k = i * c + j;//仍然是拉直的思想
                res[i][j] = nums[k / n][k % n];
            }
        }
        return res;
    }
};

class Solution3 {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c) return nums;
        vector<vector<int> > res(r, vector<int>(c));
        for (int i = 0; i < r * c; ++i) {
            res[i / c][i % c] = nums[i / n][i % n];
        }
        return res;
    }
};


int main()
{

}