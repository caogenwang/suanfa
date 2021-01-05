#include <vector>
#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
void adjust(int i,vector<int> &nums,int length);
void adjustHeap(vector<int> &nums,int i,int length);
vector<int> Top_K(vector<int> &nums,int k)
{
    vector<int> vec;
    for (int i = nums.size() / 2 - 1; i >= 0; i--)
    {
        adjustHeap(nums,i,nums.size());
    }

    for (int j = nums.size() - 1; j >= nums.size() - k; j--)
    {
        vec.push_back(nums[0]);
        ::swap(nums[0],nums[j]);
        adjust(0,nums,j);
    }
    return vec;
}


void adjustHeap(vector<int> &nums,int i,int length)
{
        int temp = nums[i];//先取出当前元素i
        for(int k=i*2+1;k<length;k=k*2+1){//从i结点的左子结点开始，也就是2i+1处开始
            if(k+1<length && nums[k]<nums[k+1]){//如果左子结点小于右子结点，k指向右子结点
                k++;
            }
            if(nums[k] >temp){//如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
                nums[i] = nums[k];
                i = k;
            }else{
                break;
            }
        }
        nums[i] = temp;//将temp值放到最终的位置
}
void adjust(int i,vector<int> &nums,int length)
{
    while((2*i+1)<length)
    {
        int k = 2*i+1;//左孩子
        if ((k+1)<length&& nums[k] < nums[k+1])
        {
            k = k+1;
        }
        if (nums[k] > nums[i])
        {
            ::swap(nums[k],nums[i]);
        }
        i = k;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {7,2,3,4,5,1,6,0,9,12,15};
    int k = 4;
    vector<int> topK = Top_K(nums,k);

    for(auto ele:topK)
        cout<<ele<<" ";
    cout<<"\n";
    return 0;
}

