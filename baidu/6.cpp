/*
删除重复的数，但不要用高级函数
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> remove(vector<int> &nums){
    int len = nums.size();
    int max = 0;
    for (int i=0; i<nums.size(); i++) {
        if(max < nums[i])
            max = nums[i];
    }
    vector<int> record(max+1,0);
    vector<int> pos(max+1,-1);
    for (int i=0; i < len; i++) {
        record[nums[i]] ++;
        if (pos[nums[i]] == -1) {
            pos[nums[i]] = i;
        };
    }
    vector<int> res(max+1,-1);
    for (int i=0; i<record.size(); i++) {
        if (record[i] != 0) {
            res[pos[i]] = i;
        }
    }

    vector<int> res2;
    for (int i:res) {
        if(i != -1)
            res2.push_back(i);
    }
    return res2;
}

int main(){

}