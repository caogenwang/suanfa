#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int getMaxNum(vector<int> &arr)
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}

std::vector<int> getMaxWindow(vector<int> &arr,int w)
{
    vector<int> win;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        win.push_back(arr[i]);
        if (win.size() == 3)
        {
            res.push_back(getMaxNum(win));
            for (int j = 1; j < 3; j++)
            {
                win[j-1] = win[j];
            }
            win.pop_back();            
        }
    }
    return res;
}
/*计算每个滑动窗口中的最大值*/
std::vector<int> getMaxWindow3(vector<int> &arr,int w)
{
    std::deque<int> Qmax;
    int index = 0;
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

std::vector<int> getMaxWindow4(vector<int> &arr,int w)
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
        if (Qmax.front() == i - w)//超过一个窗口就得删掉队头元素，font位置记录的是最大值的下标，只要满足一个窗口，就是最大值，font中存放的元素的位置和当前的位置差一个窗口大小时，不能再成为下一个窗口的中的元素了，需要删除了
        {
            Qmax.pop_front();
        }
        if (i >= w-1)//满足一个窗口了
        {
            res.push_back(arr[Qmax.front()]);
        }
    }
    return res.reserve;
}

//采用队列方式
int getMaxNum2(deque<int> &Q)
{
    int max = Q.front();;
    for (auto it = Q.begin(); it !=  Q.end(); it++)
    {
        if (*it > max)
        {
            max = *it;
        }
    }
    return max;
}

int getMinNum2(deque<int> &Q)
{
    int min = Q.front();
    for (auto it = Q.begin(); it !=  Q.end(); it++)
    {
        if (*it < min)
        {
            min = *it;
        }
    }
    return min;
}


std::vector<int> getMaxWindow2(vector<int> &arr,int w)
{
    std::deque<int> Q;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        Q.push_back(arr[i]);
        if (Q.size() == 3)
        {
            int max = getMaxNum2(Q);
            res.push_back(max);
            Q.pop_front();
        }
    }
    return res;
}

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

int main()
{
    // std::vector<int> arr = {4,3,5,4,3,3,6,7};
    // int w = 3;
    // std::vector<int> res = getMaxWindow3(arr,w);
    // for (int i = 0; i < res.size(); i++)
    // {
    //     printf("%d ",res[i]);
    // }
    // printf("\n");
    std::vector<int> arr = {1,2,3,4,5};
    int w = 2;
    int res = getMaxNumber(arr,w);
    printf("%d\n",res);
    return 0;
}