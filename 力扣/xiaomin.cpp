#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

//窗口大小是可变的,记录下这滑动窗口的最大值
int getNum(vector<int> &arr,int value)
{
    if (arr.size()<=0)
    {
        return 0;
    }
    std::deque<int> Qmax;
    std::deque<int> Qmin;
    int i = 0;
    int j = 0;
    int res = 0;
    while (i < arr.size())//维护同一个子数组的最大最小值，j一直向右扩大，每个子数组都是以i元素开头的数组
    {
        while (j < arr.size())
        {
            while (!Qmin.empty() && arr[Qmin.back()] >= arr[j])//不为0，同时新增加的元素比较大，就得将大的删掉
            {
                Qmin.pop_back();
            }
            Qmin.push_back(j);

            while (!Qmax.empty() && arr[Qmax.back()] <= arr[j])//不为0，同时新增加的元素比较大，就得将小的删掉
            {
                Qmax.pop_back();
            }
            Qmax.push_back(j);

            if (arr[Qmax.front()] - arr[Qmin.front()] > value)
            {
                break;
            }
            j++;
        }
        if (Qmin.front() == i)//i向右扩大，扩大到一定点的时候，需要pop掉以已经不应该在队列的元素了
        {
            Qmin.pop_front();
        }
        if (Qmax.front() == i)
        {
            Qmax.pop_front();
        }
        res += j - i;//只要包含i，j位置的子数组都可以算
        i++;
    }
    return res;
}

/*计算每个滑动窗口中的最大值*/
std::vector<int> getMaxWindow(vector<int> &arr,int w)
{
    std::deque<int> Qmax;
    std::vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    { 
        while (!Qmax.empty() && arr[Qmax.back()] <= arr[i])//不为0，同时新增加的元素比较大，就得将小的删掉
        {
            Qmax.pop_back();
        }
        Qmax.push_back(i);
        if (Qmax.front() == i - w)//超过一个窗口就得删掉队头元素，font位置记录的是最大值的下标，只要满足一个窗口，就是最大值
        {
            Qmax.pop_front();
        }
        if (i >= w-1)//满足一个窗口了
        {
            res.push_back(arr[Qmax.front()]);
        }
    }
    return res;
}

/*计算每个滑动窗口中的最小值*/
std::vector<int> getMinWindow(vector<int> &arr,int w)
{
    deque<int> Qmin;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!Qmin.empty() && arr[Qmin.back()] >= arr[i])
        {
            Qmin.pop_back();
        }
        Qmin.push_back(i);

        if (Qmin.front() == i - w)
        {
            Qmin.pop_front();
        }
        if(i>= w - 1)
        {
            res.push_back(arr[Qmin.front()]);
        }
    }
    return res;
}

int main()
{
    int arr2[9] = {5,2,7,4,2,5,8,3};
    std::vector<int> arr(arr2,arr2+9);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int w = 3;
    std::vector<int> res1 = getMaxWindow(arr,w);
    for (int i = 0; i < res1.size(); i++)
    {
        cout<<res1[i]<<" ";
    }
    cout<<endl;
    std::vector<int> res2 = getMinWindow(arr,w);
    for (int i = 0; i < res2.size(); i++)
    {
        cout<<res2[i]<<" ";
    }
    cout<<endl;
    vector<int> sums;
    for (int i = 0; i < res2.size(); i++)
    {
        sums.push_back(res1[i]-res2[i]);
    }
    
    for (int i = 0; i < sums.size(); i++)
    {
        cout<<sums[i]<<" ";
    }
    cout<<endl;
    return 0;
}