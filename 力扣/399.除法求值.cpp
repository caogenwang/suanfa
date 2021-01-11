#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 
共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 
的结果作为答案。
返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。
注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
示例 1：

输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],
                    ["a","a"],["x","x"]]
输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
解释：
条件：a / b = 2.0, b / c = 3.0
问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
示例 2：

输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], 
                queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
输出：[3.75000,0.40000,5.00000,0.20000]
示例 3：

输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
输出：[0.50000,2.00000,-1.00000,-1.00000]

*/
static vector<string> duplicate_removal(vector<string> eq)
{   
    
    set<char> s0;
    set<char> s1;
    for(int i=0;i<eq[0].length();i++)
    {   
        s0.insert(eq[0][i]);
    }

    for(int i=0;i<eq[1].length();i++)
    {   
        s1.insert(eq[1][i]);
    }
    string rt1;;
    for (set<char>::iterator it = s0.begin(); it != s0.end(); it++)
    {
        if(s1.find((*it)) == s1.end())
        {
            rt1 += (*it);
        }
    }

    string rt2;;
    for (set<char>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        if(s0.find((*it)) == s0.end())
        {
            rt2 += (*it);
        }
    }
    vector<string> vs{rt1,rt2};
    return vs;
}

struct Node{
    string s;
    vector<struct Node> neighbers;
    Node():s(nullptr),neighbers({}){}
};
vector<Node> graph;
class Solution1 {
public:
    vector<double> calcEquation(vector<vector<string> >& equations, 
                                vector<double>& values, vector<vector<string> >& queries) 
    {
        vector<double> ret;
        
        return ret;
    }
};

class Solution2 {
public:
    vector<double> calcEquation(vector<pair<string, string> > equations, 
                                vector<double>& values, vector<pair<string, string> > queries) {
        vector<double> res;
        for (int i = 0; i < equations.size(); ++i) {
            m[equations[i].first][equations[i].second] = values[i];
            m[equations[i].second][equations[i].first] = 1.0 / values[i];
        }//正反key都放入了

        for (auto query : queries) {
            unordered_set<string> visited;
            double t = helper(query.first, query.second, visited);
            res.push_back((t > 0.0) ? t : -1);
        }
        
        return res;
    }
    double helper(string up, string down, unordered_set<string>& visited) {
        if (m[up].count(down)) 
            return m[up][down];

        for (auto a : m[up]) {
            if (visited.count(a.first)) 
                continue;
            visited.insert(a.first);

            double t = helper(a.first, down, visited);
            if (t > 0.0) 
                return t * a.second;
        }
        return -1.0;
    }

private:
    unordered_map<string, unordered_map<string, double> > m;
};

class Solution3 {
public:
    //2020.12.7 日

    //全局变量2个
    vector<double> res;
    bool Nofand;

    void dfs(unordered_map< string , vector<pair<string,double>> >& g, unordered_map<string,int>& visit,string val, const string& target, const double& path){
        //如果节点已经相连接，那没 必要再dfs搜索了，直接返回
        if( Nofand == false )
            return;
        
        if( val == target){
            Nofand = false;
            res.push_back(path);
            return;
        }

        for(int j = 0;j<g[val].size(); ++j){
            //检查与val相连接的点，是否已经访问过了。没访问过继续dfs
            if(visit[ g[val][j].first ] == 0 ){
                visit[ g[val][j].first ] = 1;
                dfs( g,visit, g[val][j].first, target, path*g[val][j].second );
                visit[ g[val][j].first ] = 0;
            }
        }
    }

    vector<double> calcEquation(vector<vector<string> >& equations, 
                                vector<double>& values, vector<vector<string> >& queries) 
    {
        //string - string(double)  a连接b(b带上权值)
        unordered_map<string , vector<pair<string,double> > > g;
        unordered_map<string,int> visit;

        //构建无向图，a-b的value是3 的话 ，b-a是3的倒数
        for(int i =0;i<equations.size();++i){
            g[equations[i][0]].push_back(make_pair(equations[i][1], values[i] ));
            g[equations[i][1]].push_back(make_pair(equations[i][0], 1.0/values[i]));
        }

        //遍历queries，对每一组进行dfs计算结果。
        //如果相连接，就把 路径上的权值相乘就是结果

        for(int i =0; i<queries.size();++i){
            
            //如果queries[0]是不存在的，直接出结果：-1
            if( g.find(queries[i][0]) == g.end()){
                res.push_back(-1.0);
                continue;
            }
                
            //设置一个全局变量，如果进行dfs后，queries[0]到不了queries[1]，Nofind = true;
            Nofand = true;

            visit[queries[i][0]]=1;
            dfs(g,visit,queries[i][0],queries[i][1],1);
            visit[queries[i][0]]=0;

            if( Nofand )
            res.push_back(-1.0);
        }

        return res;
    }
};


struct Node {
    double value;
    Node* parent;
    Node() : parent(this) {}
    Node(double v) : value(v), parent(this) {}
};

class Solution4 {
    unordered_map<string, Node*> m;

    Node* find(Node* n) {
        if (n->parent != n) {
            n->parent = find(n->parent);
        }
        return n->parent;
    }
   
    void merge(Node* n1, Node* n2, double val) {
        Node* p1 = find(n1);
        Node* p2 = find(n2);
        double ratio = n2->value * val / n1->value;
        for (auto it : m) {
            if (find(it.second) == p1) {
                it.second->value *= ratio;
            }
        } 
        p1->parent = p2;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            if (m.find(a) == m.end()) m[a] = new Node(values[i]);
            if (m.find(b) == m.end()) m[b] = new Node(1.0);
            merge(m[a], m[b], values[i]);
        }
        vector<double> res;
        for (auto q : queries) {
            if (m.find(q[0]) == m.end() || m.find(q[1]) == m.end() || find(m[q[0]]) != find(m[q[1]])) {
                res.push_back(-1);
            } else {
                res.push_back(m[q[0]]->value / m[q[1]]->value);
            }
        }
        return res;
    }
};

struct Value {
    int status;
    double val;
    Value(): status(0), val(0) {}
    Value(int s, double v) : status(s), val(v) {}
};

class Solution5 {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {      
        unordered_map<string, int> store;
        int n = 0;
        for (auto e : equations) {
            if (store.find(e[0]) == store.end())
                store[e[0]] = n++;
            if (store.find(e[1]) == store.end())
                store[e[1]] = n++;
        }

        vector<vector<Value>> graph(n, vector<Value>(n, Value()));
        for (int i = 0; i < equations.size(); ++i) {
            int ia = store[equations[i][0]];
            int ib = store[equations[i][1]];
            graph[ia][ib] = Value(1, values[i]);
            graph[ib][ia] = Value(1, 1/values[i]);
        }
        
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (graph[i][j].status == 0 && graph[i][k].status == 1 && graph[k][j].status == 1) {
                        graph[i][j] = Value(1, graph[i][k].val * graph[k][j].val);
                    }
                }
            }
        }
        
        vector<double> res;
        for (auto q : queries) {
            if (store.find(q[0]) == store.end() || store.find(q[1]) == store.end()) {
                res.push_back(-1);
                continue;
            } 
            int ia = store[q[0]];
            int ib = store[q[1]];
            double r = graph[ia][ib].status == 1 ? graph[ia][ib].val : -1;
            res. push_back(r);
        }
        return res;
    }
};


class Solution6 {
public:
    vector<double> calcEquation(vector<vector<string> > equations, 
                                vector<double>& values, vector<vector<string> > queries) {
        vector<double> res;
        for (int i = 0; i < equations.size(); ++i) {
            m[equations[i][0]][equations[i][1]] = values[i];
            m[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }//正反key都放入了

        for (auto query : queries) {
            unordered_set<string> visited;
            double t = helper(query[0], query[1], visited);
            res.push_back((t > 0.0) ? t : -1);
        }
        
        return res;
    }
    double helper(string up, string down, unordered_set<string>& visited) {
        if (m[up].count(down)) 
            return m[up][down];

        for (auto a : m[up]) {
            if (visited.count(a.first)) 
                continue;
            visited.insert(a.first);

            double t = helper(a.first, down, visited);
            if (t > 0.0) 
                return t * a.second;
        }
        return -1.0;
    }

private:
    unordered_map<string, unordered_map<string, double> > m;
};

int main()
{
    vector<string> tmp1[3]{{"a","b"},{"b","c"},{"bc","cd"}};
    vector<vector<string> > equations(tmp1,tmp1+3);
    vector<double> values{1.5,2.5,5.0};
    
    vector<string> tmp2[4]{{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    vector<vector<string> > queries(tmp2,tmp2+4);

    Solution1 s1;
    vector<double> res = s1.calcEquation(equations,values,queries);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<endl;
    }

    vector<string> vs = duplicate_removal({"a","b"});
    cout<<vs[0]<<" "<<vs[1]<<endl;

    unordered_multimap<string, double> m;
    m.insert(std::pair<string,double>("s",10));
    m.insert(std::pair<string,double>("s",11));
    m.insert(std::pair<string,double>("s",12));
    m.count("s");
    cout<<m.count("s")<<endl;

}