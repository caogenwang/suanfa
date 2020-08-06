#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

/*hash太耗费空间，数据量大时很浪费*/
void noMore41(vector<int> &nums)
{
    unordered_map<int,int> hash_map;
    for (int i = 0; i < nums.size(); i++)
    {
        hash_map[nums[i]]++;
    }
    int len = nums.size() / 4;
    for (unordered_map<int,int>::iterator it=hash_map.begin();it != hash_map.end();it++)
    {
        if ((*it).second > len)
        {
            cout<<(*it).first<<endl;
        }
    }
}

void noMore412(vector<int> &nums)
{
    map<int,int> xmap;
    for (int i = 0; i < nums.size(); i++)
    {
        if(xmap.find(nums[i]) == xmap.end())
        {
            if (xmap.size() < 3)
            {
                xmap[nums[i]] = 1;
            }
            else
            {
                for (map<int,int>::iterator it=xmap.begin();it != xmap.end(); it++)
                {
                    (*it).second -= 1;
                    if ((*it).second <= 0)
                    {
                        xmap.erase((*it).first);
                    }
                }
            }
        }
        else
        {
            xmap[nums[i]] ++;
        }
    }
    for (map<int,int>::iterator it=xmap.begin();it != xmap.end(); it++)
    {
        cout<<(*it).first<<endl;
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,1,1,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4};
    noMore412(nums);
    return 0;
}
