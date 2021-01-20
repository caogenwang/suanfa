
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution1 {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if (flowerbed.empty()) 
            return false;

        if (flowerbed[0] == 0) 
            flowerbed.insert(flowerbed.begin(), 0); 
        if (flowerbed.back() == 0) 
            flowerbed.push_back(0);

        int len = flowerbed.size(), cnt = 0, sum = 0;
        for (int i = 0; i <= len; ++i) {
            if (i < len && flowerbed[i] == 0)//先计算走到i的时候，有多少个连续的0，
                ++cnt;
            else//一旦不等于0，立刻计算能放的花盆数
            {
                sum += (cnt - 1) / 2;
                cnt = 0;
            }
        }
        return sum >= n;
    }
};

class Solution2 {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (n == 0) 
                return true;
            if (flowerbed[i] == 0) {
                int next = (i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1]);
                int pre = (i == 0 ? 0 : flowerbed[i - 1]);
                if (next + pre == 0) {
                    flowerbed[i] = 1;
                    --n;
                }
            }
        }
        return n <= 0;
    }
};

class Solution3 {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (int i = 1; i < flowerbed.size() - 1; ++i) {
            if (n == 0) 
                return true;
            if ((flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1]) == 0) {
                --n;
                ++i;
            }
        }
        return n <= 0;
    }
};

int main()
{
    vector<int> flowerbed{1,0,0,0,1};
    int n = 2;
    Solution1 s1;
    bool can = s1.canPlaceFlowers(flowerbed,n);
    cout<<"can:"<<can<<endl;
    

    Solution3 s3;
    can = s3.canPlaceFlowers(flowerbed,n);
    cout<<"can:"<<can<<endl;
    
    Solution2 s2;
    can = s2.canPlaceFlowers(flowerbed,n);
    cout<<"can:"<<can<<endl;
}