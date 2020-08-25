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

std::vector<int> getMaxWindow3(vector<int> &arr,int w)
{
    std::deque<int> Qmax;
    int index = 0;
    std::vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    { 
        while (!Qmax.empty() && arr[Qmax.back()] <= arr[i])
        {
            Qmax.pop_back();
        }
        Qmax.push_back(i);
        if (Qmax.front() == i - w)//超过一个窗口就得删掉队头元素
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

//窗口大小是可变的
int getMaxNumbersOfSubArray(vector<int> &arr,int value)
{
    return 0;
}

int main()
{
    std::vector<int> arr = {4,3,5,4,3,3,6,7};
    int w = 3;
    std::vector<int> res = getMaxWindow3(arr,w);
    for (int i = 0; i < res.size(); i++)
    {
        printf("%d ",res[i]);
    }
    printf("\n");
    return 0;
}