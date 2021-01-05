#include <iostream>
#include <vector>
#include <memory>
#include <unistd.h>
using namespace std;

int find(vector<int> nums)
{
    int start = 0;
    int stop = nums.size() - 1;

    while (1)
    {
        sleep(1);
        int mid = (start + stop)/2 - start;
        int pre = nums[mid] - nums[mid - 1];
        int aft = nums[mid] - nums[mid + 1];
        std::cout<<"mid:"<<mid<<std::endl;
        if (pre > 0 && aft > 0)
        {
            return mid;
        }
        else if(pre > 0 && aft < 0)
        {
            start = mid + 1;
        }
        else if(pre < 0 && aft > 0)
        {
            stop = mid - 1;
        }
    }
    return 0;
}
int main()
{
    vector<int> nums = {7,6,5,4,3,2,1,3,5,7,8,9};
    int n = find(nums);

    // std::cout<<n<<std::endl;

}