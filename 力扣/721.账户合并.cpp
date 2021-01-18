#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

/*medium*/

class Solution {//很多条件不满足
public:
    vector<vector<string> > accountsMerge(vector<vector<string> >& accounts) {
        vector<int> visited(accounts.size(),0);
        vector<vector<string> > res;
        bool same_account = false;
        for (int i = 0; i < accounts.size(); i++)
        {
            if (visited[i] == 1)
            {
                continue;
            }
            vector<string> acc;
            acc.push_back(accounts[i][0]);
            set<string> mails;
            for (int m = 1; m < accounts[i].size(); m++)
            {
                mails.insert(accounts[i][m]);
            }
            
            for (int j = i+1; j < accounts.size(); j++)
            {
                if (accounts[i][0] != accounts[j][0])
                {
                    visited[j] = 1;
                    res.push_back(accounts[j]);
                }
                else
                {
                    same_account = false;
                    for (int n = 1; n < accounts[j].size(); n++)
                    {
                        if (mails.find(accounts[j][n]) != mails.end())
                        {
                            same_account = true;
                            break;
                        }
                        else
                        {
                            visited[j] = 1;
                            res.push_back(accounts[j]);
                        }
                    }
                    if(same_account)
                    {
                        visited[j] = 1;
                        for (int l = 1; l < accounts[j].size(); l++)
                        {
                            mails.insert(accounts[j][l]);
                        }
                    }
                }
            }
            for (set<string>::iterator it = mails.begin();it != mails.end();it++)
            {
                acc.push_back(*it);
            }
            visited[i];
            res.push_back(acc);
        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<string> > accountsMerge(vector<vector<string> >& accounts) {
        vector<vector<string> > res;
        unordered_map<string, string> root;
        unordered_map<string, string> owner;
        unordered_map<string, set<string> > m;
        for (auto account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                root[account[i]] = account[i];//所有的邮箱建立一张表,过滤掉很多重复项
                cout<<account[i]<<endl;
                owner[account[i]] = account[0];//所有的邮箱对应的账户建立一张表
            }
        }
        cout<<"---------------------"<<endl;
        for(unordered_map<string, string>::iterator it = root.begin();it != root.end();it ++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<"---------------------"<<endl;
        for(unordered_map<string, string>::iterator it = owner.begin();it != owner.end();it ++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<"---------------------"<<endl;
        /*
            首先对帐号的第一个邮箱调用 find 函数，得到其父串p，然后遍历之后的邮箱，
            对每个遍历到的邮箱先调用 find 函数，将其父串的 root 值赋值为p，
            这样做相当于将相同账号内的所有邮箱都链接起来了.
        */
        for (auto account : accounts) {
            string p = find(account[1], root);
            for (int i = 2; i < account.size(); ++i) {
                cout<<"p:"<<p<<endl;
                root[find(account[i], root)] = p;//重复的点都是一个账户的了
            }
        }
        cout<<"---------------------"<<endl;
        for(unordered_map<string, string>::iterator it = root.begin();it != root.end();it ++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
        /*
            接下来要做的就是再次遍历每个账户内的所有邮箱，先对该邮箱调用 find 函数，找到父串，
            然后将该邮箱加入该父串映射的集合汇总，这样就就完成了合并
        */
        for (auto account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                cout<<"account:"<<account[i]<<endl;
                m[find(account[i], root)].insert(account[i]);//将account放入父类的集合，set起到过滤的作用
            }
        }
        /*
            最后只需要将集合转为字符串数组，加入结果 res 中，
            通过 owner 映射找到父串的用户名，加入字符串数组的首位置
        */
        for (auto a : m) {
            vector<string> v(a.second.begin(), a.second.end());
            v.insert(v.begin(), owner[a.first]);//头部插入name
            res.push_back(v);
        }
        /*map和set都起到了去重的作用*/
        /*先合并所有的邮箱，然后根据邮箱对应的账户，找到名字*/
        return res;
    }
    string find(string s, unordered_map<string, string>& root) {
        return root[s] == s ? s : find(root[s], root);
    }
};

/*官方*/
class Djset {
public:
    vector<int> parent;  // 记录节点的根
    vector<int> rank;  // 记录根节点的深度（用于优化）
    Djset(int n): parent(vector<int>(n)), rank(vector<int>(n)) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        // 压缩方式：直接指向根节点
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) 
                rank[rootx] += 1;
        }
    }
};

class Solution3 {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        vector<vector<string> > res;
        // 作用：存储每个邮箱属于哪个账户 ，同时 在遍历邮箱时，判断邮箱是否出现过
        // 格式：<邮箱，账户id>
        unordered_map<string, int> um;
        int n = acc.size();
        Djset ds(n);
        for (int i = 0; i < n; i++) {
            int m = acc[i].size();
            for (int j = 1; j < m; j++) {
                string s = acc[i][j];
                if (um.find(s) == um.end()) {
                    um[s] = i;
                } else {
                    ds.merge(i, um[s]);
                }
            }
        }
        // 作用： 存储每个账户下的邮箱
        // 格式： <账户id, 邮箱列表> >
        // 注意：这里的key必须是账户id，不能是账户名称，名称可能相同，会造成覆盖
        unordered_map<int, vector<string> > umv;
        for (auto& [k, v] : um) umv[ds.find(v)].emplace_back(k);
        for (auto& [k, v] : umv){
            sort(v.begin(), v.end());
            vector<string> tmp(1, acc[k][0]);
            tmp.insert(tmp.end(), v.begin(), v.end());
            res.emplace_back(tmp);
        } 


        return res;
    }
};


int main()
{
    vector<vector<string> > accounts{
                                    {"John", "johnsmith@mail.com", "john00@mail.com"}, 
                                    {"John", "johnnybravo@mail.com"}, 
                                    {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, 
                                    {"Mary", "mary@mail.com"}
                                    };
    vector<vector<string> > accounts1{  {"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},
                                        {"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},
                                        {"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},
                                        {"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},
                                        {"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}
                                    };
    vector<vector<string> > accounts2{  {"John", "a@gmail.com", "b@gmail.com"},
                                        {"John", "c@gmail.com", "d@gmail.com"},
                                        {"John", "a@gmail.com", "c@gmail.com"}};
    Solution2 s;

    vector<vector<string> > res = s.accountsMerge(accounts2);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    
}

/*
[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  
 ["John", "johnnybravo@mail.com"], 
 ["Mary", "mary@mail.com"]]

*/

