#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*我们称所有包含大于或等于三个连续字符的分组为 较大分组 。*/
class Solution1 {//此方法无法解决不连续的重复的key，所以必须按照顺序进行遍历
public:
    struct Record{
        int start;
        int count;
        Record(int s,int c):start(s),count(c){}
    };

    vector<vector<int> > largeGroupPositions(string &s) {
        vector<vector<int> > result;
        map<char,Record> m;
        typedef map<char,Record>::iterator map_it;
        map_it it;
        for(int i=0;i<s.size();i++)
        {
            if ((it = m.find(s[i])) != m.end())//存在
            {  
                cout<<it->first<<endl;

                int start = it->second.start;
                int count = it->second.count;
                cout<<"count "<<count<<endl;
                Record r(start,count+1);
                m.erase(it);
                m.insert(std::pair<char,Record>(s[i],r));
            }
            else
            {
                Record r(i,1);
                m.insert(std::pair<char,Record>(s[i],r));
            }
        }
        for (map_it it = m.begin(); it != m.end(); it++)
        {
            int start = it->second.start;
            int count = it->second.count;
            if (count>=3)
            {
                vector<int> tv;
                tv.push_back(start);
                tv.push_back(count+start-1);
                result.push_back(tv);
            }
        }
        return result;
    }
};

class Solution2 {
public:
    vector<vector<int> > largeGroupPositions(string s) {
        vector<vector<int> > ret;
        int n = s.size();
        int num = 1;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || s[i] != s[i + 1]) {
                if (num >= 3) {
                    ret.push_back({i - num + 1, i});//注意这种用法
                }
                num = 1;
            } else {
                num++;
            }
        }
        return ret;
    }
};

class Solution3 {
public:
    vector<vector<int> > largeGroupPositions(string s) {
        vector<vector<int> > ret;
        int n = s.size();
        int num = 1;
        for (int i = 0; i < n; i++)
        {
            if (i == n-1 || s[i+1] != s[i])
            {
                if (num >= 3)
                {
                    ret.push_back({i-num+1,i});//花括号初始化
                    num = 1;
                }
            }
            else
            {
                num++;
            }
        }
        return ret;
    }
};

class Solution_2 {
public:
    vector<vector<int> > largeGroupPositions(string s)
    {
        vector<vector<int> > res;
        int num = 1;
        for (int i = 0; i < s.length(); i++) {
            if (i == s.length() - 1 || s[i] != s[i+1]) {
                if (num >= 3) {
                    res.push_back({i-num+1,i});
                }
                num = 1;
            }
            else
                num ++;
        }
        return res;
    }
};

int main()
{
    string s = "abcdddeeeeaabbbcd";
    Solution2  solution;     
    vector<vector<int> > vv = solution.largeGroupPositions(s);
    cout<<"---------"<<endl;
    for (int i = 0; i < vv.size(); i++)
    {
        vector<int> tmp = vv[i];
        for (int j = 0; j < tmp.size(); j++)
        {
            cout<<tmp[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}