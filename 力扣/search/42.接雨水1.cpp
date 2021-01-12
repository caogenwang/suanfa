#include <iostream>
#include <vector>
#include <queue>
#include<numeric>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<int>& heightMap) {
        
    }
};

int main()
{
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    int w = s.trapRainWater(height);
    cout<<w<<endl;
}