#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <fstream>
#include <limits.h>
using namespace std;
//给出一个只包含0和1的二维矩阵，找出最大的全部元素都是1的长方形区域，返回该区域的面积。
class Solution1 {
public:
    int LagestRectangle(vector<int> &height) {
        int res = 0;
        for(int i=0;i<height.size();++i)
        {
            if(i+1 < height.size() && height[i] <= height[i+1])
            {
                continue;
            }
            int minH = height[i];
            printf("i:%d\n");
            for (int j = i; j >= 0; --j)
            {
                printf("j:%d\n",height[j]);
                minH = min(minH,height[j]);
                printf("min:%d\n",minH);
                int area = minH*(i - j + 1);
                printf("area:%d\n",area);
                res = max(res,area);
            }
            printf("\n");
        }
        return res;
    }
};

class Solution2 {
public:
    int LagestRectangle(vector<int> &height) {
        int res = 0;
        stack<int> st;
        height.push_back(0);
        for(int i=0;i<height.size();++i)
        {
            printf("i:%d,h:%d\n",i,height[i]);
            if(st.empty() || height[st.top()]< height[i]){//单调递增的栈
                printf("push_i:%d\n",height[i]);
                st.push(i);
            }
            else
            {
                int cur = st.top();
                printf("pop_i:%d,cur:%d,h:%d\n",i,cur,height[cur]);
                st.pop();
                int cal = height[cur] * (st.empty() ? i : (i - st.top() - 1));
                printf("cal:%d\n",cal);
                res = max(res,cal);
                printf("res:%d\n",res);
                --i;
            }
            printf("\n");
        }
        return res;
    }
};

class Solution3 {
public:
    int LagestRectangle(vector<int> &height) {
        int res = 0;
        stack<int> st;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                int cur = st.top(); st.pop();
                res = max(res, height[cur] * (st.empty() ? i : (i - st.top() - 1)));
            }
            st.push(i);
        }
        cout<<res<<endl;
        return res;
    }
};

int main(int argc,char **argv)
{
    int a[6] = {2,1,5,6,2,3};
    vector<int> b(a,a+6);
    vector<int> &c = b;
    Solution3 s;
    s.LagestRectangle(c);
    return 0;
}