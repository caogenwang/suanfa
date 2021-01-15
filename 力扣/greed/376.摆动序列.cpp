#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const static int START = 0;
        const static int UP = 1;
        const static int DOWN = 2;
        int status = START;
        if (nums.size() < 2)
        {
            return nums.size();
        }

        int length = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            switch (status)
            {
                case START:
                    if (nums[i]>nums[i-1])
                    {
                        status = UP;
                        length ++;
                    }
                    else if(nums[i]<nums[i-1])
                    {
                        status = DOWN;
                        length ++;
                    }
                    break;
                case UP:
                    if (nums[i]<nums[i-1])
                    {
                        status = DOWN;
                        length ++;
                    }
                    break;
                case DOWN:
                    if (nums[i]>nums[i-1])
                    {
                        status = UP;
                        length ++;
                    }
                    break;
                default:
                    break;
            }
        }
        return length;
    }
};

int main()
{
    vector<int> nums{0,0};
    Solution s1;
    int length = s1.wiggleMaxLength(nums);
    cout<<length<<endl;
}