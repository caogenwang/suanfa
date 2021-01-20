#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
/*
    给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，
    其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0 开始）。
    你可以 任意多次交换 在 pairs 中任意一对索引处的字符

    输入：s = "dcab", pairs = [[0,3],[1,2]]
    输出："bacd"
    解释： 
    交换 s[0] 和 s[3], s = "bcad"
    交换 s[1] 和 s[2], s = "bacd"
*/

class Solution1 {
public:
    string smallestStringWithSwaps(string s, vector<vector<int> >& pairs) {
        string s1 = s;
        for (int i = 0; i < pairs.size(); i++)
        {
            vector<int> tmp = pairs[i];
            if (s1[tmp[0]] > s1[tmp[1]])
            {
                swap(s1,tmp[0],tmp[1]);
            }
        }
        return s1;
    }
    void swap(string &s,int p1,int p2)
    {
        char c = s[p1];
        s[p1] = s[p2];
        s[p2] = c;
    }
};

class Solution
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int> >& pairs) 
    {
        for (int i = 0; i < s.size(); i++) 
            p.push_back(i);//父节点设置为自己
        
        for(int i=0;i<p.size();i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
        cout<<"----------------"<<endl;

        for (auto& it : pairs)
        {
            int px = find(it[0]), py = find(it[1]);//先寻找父节点，查看父节点是否一致
            if (px != py) 
                p[px] = py;//不一致则设置为一致
        }
        for(int i=0;i<p.size();i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
        cout<<"----------------"<<endl;

        unordered_map<int, vector<int> > mem;
        for (int i = 0; i < p.size(); i++) 
        {
            mem[find(p[i])].push_back(s[i]);//把每个父节点下的子节点都放入到vector中
        }

        for (auto& it : mem)
        {
            vector<int> tmp = it.second;
            for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
            {
                printf("%c ",(*it));
            }
            cout<<endl;
        }
        cout<<"----------------"<<endl;

        for (auto& it : mem) 
            sort(it.second.begin(), it.second.end(), greater<int>());//从大到小进行排序，后边取的时候，是从尾部开始取的
        
        for (auto& it : mem)
        {
            vector<int> tmp = it.second;
            for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
            {
                printf("%c ",(*it));
            }
            cout<<endl;
        }
        cout<<"----------------"<<endl;

        string res;
        for (int i = 0; i < s.size(); i++) 
        {
            int x = find(i);//找到i的父节点
            res.push_back(mem[x].back());//依次去取对应的字符
            mem[x].pop_back();
        }
        return res;
    }
    
private:
    vector<int> p;
    
    int find(int x)
    {
        if (x != p[x])//自己的父节点就是自己的时候就退出寻找
            p[x] = find(p[x]);
        return p[x];
    }
};


int main()
{
    string s = "dcabefg";
    vector<vector<int> > pairs{{0,3},{2,6},{1,2},{3,5}};
    Solution s0;
    string s2 = s0.smallestStringWithSwaps(s,pairs);
    cout<<s2<<endl;
    return 0;
}

/*
bcad
bacd
cabd
*/