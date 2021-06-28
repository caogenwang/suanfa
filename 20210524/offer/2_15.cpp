#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int nums = 0;
        int len = sizeof(uint32_t)*8;
        while (n>0)
        {
            n = n & (n-1);
            nums++;
        }
        std::cout<<len<<std::endl;
        return nums;
    }
};

int main(){
    uint32_t value = 0b00000000000000000000000000001011;
    Solution s;
    int num = s.hammingWeight(value);
    std::cout<<num<<endl;
}