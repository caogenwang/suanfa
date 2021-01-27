#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int> >& dominoes) {//超出时间限制
        int nums = 0;
        vector<int> visited(dominoes.size(),0);
        for(int i = 0;i < dominoes.size();i ++)
        {
            if (visited[i] == 1)
                continue;
            visited[i] == 1;
            for (int j = i + 1; j < dominoes.size(); j++)
            {   
                if (visited[j] == 1)
                    continue;
                if((dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1])
                    || (dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0]))
                {
                    nums++;
                }
                visited[j] = 1;
            }
        }
        return nums++;
    }
};

class Solution2 {//并查集
public:
    int numEquivDominoPairs(vector<vector<int> >& dominoes) {
        int nums = 0;
        unordered_multimap<int,int> rows;
        unordered_multimap<int,int>::iterator it;
        for (int i = 0; i < dominoes.size(); i++)
        {
            rows.insert(make_pair(dominoes[i][0],dominoes[i][1]));
        }

        for (int i = 0; i < dominoes.size(); i++)
        {
            if (rows.count(dominoes[i][0]) > 1)
            {
                nums += rows.count(dominoes[i][0])/2;
                rows.erase(dominoes[i][0]);
            }
            else
            {
                it = rows.find(dominoes[i][1]);
                if(it != rows.end() && it->second == dominoes[i][0])
                {
                    nums++;
                    rows.erase(it->second);
                }
            }
        }
        return nums;
    }
};

class Solution3 {
public:
    int numEquivDominoPairs(vector<vector<int> >& dominoes) {
        for (int i = 0; i < dominoes.size(); i++)
        {
            sort(dominoes[i].begin(),dominoes[i].end());
        }
        map<vector<int>,int> mp;
        for (int i = 0; i < dominoes.size(); i++)
        {
            vector<int> tmp = dominoes[i];
            mp[tmp] ++; 
        }
        int res = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second > 1)
            {
                int n = it->second;
                res += n*(n-1)/2;//两两组合是一对？
            }
        }
        return res;
    }
};

class Solution4 {
    int numEquivDominoPairs(vector<vector<int> >&dominoes) {
        map<int,int> mp;
        int res = 0;
        for(int i = 0; i < dominoes.size(); i++){
            int m = dominoes[i][0];
            int n = dominoes[i][1];
            int k = m > n ? m * 10 + n : n * 10 + m;
            mp[k] ++;
        }
        for(auto && i = mp.begin(); i != mp.end(); i++){
            res += i->second * (i->second - 1) / 2;
        }
        return res;
    }
};
class Solution5 {
 int numEquivDominoPairs(vector<vector<int> >& dominoes) {
        int ans = 0;
        map<int,int> cp;
        for(auto && arr:dominoes){
            sort(arr.begin(),arr.end());
            ans+=cp[arr[0]*10+arr[1]]++;
        }
        return ans;
    }
};



int main()
{
    vector<vector<int> >dominoes {{1,2},{2,1},{3,4},{5,6}};
    Solution2 s;
    int res = s.numEquivDominoPairs(dominoes);
    cout<<res<<endl;
}