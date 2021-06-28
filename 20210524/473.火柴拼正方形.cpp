#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4)
            return false;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if (sum%4){
            return false;
        }
        std::sort(nums.rbegin(),nums.rend(),greater<int>());
        int bucket[4] = {0};
        return generate(0,nums,sum/4,bucket);
    }

    bool generate(int i,vector<int>&nums,int target,int bucket[])
    {
        if(i>=nums.size())
        {
            return bucket[0] == target && bucket[1] == target && bucket[2] == target && bucket[3] == target;
        }

        for (int j = 0; j < 4; j++)
        {
            if (bucket[j] + nums[i] > target)
            {
                continue;//放下一个篮子
            }
            bucket[j] += nums[i];
            if (generate(i+1,nums,target,bucket))
            {
                return true;
            }
            bucket[j] -= nums[i];
        }
        return false;
    }
};
void d(){
for(int i = 0; i < 4; i++) {
           //第index根火柴在第i条边上的尝试，如果放入当前火柴后该边长度 不大于 正方形边长，则符合要求
            if (this.sums[i] + element <= this.possibleSquareSide) {
                //将第index根火柴放入第i条边
                this.sums[i] += element;
                //考虑下一根火柴
                if (this.dfs(index + 1)) {
                    return true;
                }
               //将第index根火柴从第i条边 抽出，让该火柴可以放入其他的边
                this.sums[i] -= element;
            }
        }
}

int main(){

}