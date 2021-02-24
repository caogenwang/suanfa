#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res(A.size());
        for (int i = 0; i < A.size(); ++i) {
            for (int j = (int)A[i].size() - 1; j >= 0; --j) {
                res[i].push_back(!A[i][j]);
            }
        }
        return res;
    }
}