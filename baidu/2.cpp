/*
2. 向左移动k位
k = 3
[1,2,3,4,5,6,7]  ->  [5,6,7,1,2,3,4]
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
void move_k(vector<int> &nums,int k){
    for (int i = 0; i < k; i++) {
        int tmp = nums.back();
        nums.erase(nums.end()-1);
        nums.insert(nums.begin(), tmp);
    }
}
int main(){
    
}
