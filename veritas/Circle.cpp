#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
       if(n<=0||m<=0)
            return -1;
        int last=0;
        for(int i=2;i<=n;i++)
            last=(last+m)%i;
        return last;
    }
};

class Solution2 {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n <= 0) return -1;
        list<int> lt;
        for (int i=0; i<n; ++i)
            lt.push_back(i);
        int index = 0;
        while (n > 1) {
            index = (index + m - 1) % n;
            auto it = lt.begin();
            std::advance(it, index); // 让it向后移动index个位置
            lt.erase(it);
            --n;
        }
        return lt.back();
    }
};

int main(){
    int n = 5;
    int k = 3;
    Solution s;
    int l = s.LastRemaining_Solution(n,k);
    cout<<l<<endl;
}