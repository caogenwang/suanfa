#include <vector>
using namespace std;
class Solution{
    public:
        bool jump(vector<int>&num)
        {
            int maxReach = 0;
            for(int i=0;i<num.size() && i<=maxReach;i++){
                maxReach = ::max(maxReach,i+num[i]);  /// 跳到该点后还能到达的极限
                printf("maxreach:%d\n",maxReach);
            }
            if(maxReach<num.size()-1)
                return false;
            return true;
        }
};
int main()
{
    vector<int> nums = {2,3,1,1,4};
    Solution s;
    printf("%s\n",s.jump(nums)?"true":"false");
}