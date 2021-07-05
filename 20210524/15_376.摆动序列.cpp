#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int length = 1;
        const static int START = 0;
        const static int UP = 1;
        const static int DOWN = 2;
        if (nums.size() <= 2)
            return nums.size();
        int state = START;
        for (int i = 1; i < nums.size(); i++)
        {

            switch (state)
            {
                case START:
                    if (nums[i]>nums[i-1])
                    {
                        state = UP;
                        length ++;
                    }
                    else
                    {
                        state = DOWN;
                        length ++;
                    }
                    break;

                case DOWN:
                    if (nums[i] > nums[i-1])
                    {
                        state = UP;
                        length++;
                    }
                    break;
                case UP:
                    if (nums[i] < nums[i-1])
                    {
                        state = DOWN;
                        length++;
                    }
                    break;
                default:
                    break;
            }
        }
        return length;
    }
};

int main(){

}