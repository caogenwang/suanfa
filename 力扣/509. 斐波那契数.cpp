#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution1 {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        return fib(n-1)+fib(n-2);
    }
};

class Solution2 {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;

        int a = 0;
        int b = 1;
        int c = 0;
        for (int i = 2; i <= n; i++)
        {
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};

class Solution3 {
public:
    int fib(int N) {
        if (N <= 1) return N;
        vector<int> dp(N + 1);
        dp[0] = 0; 
        dp[1] = 1;
        for (int i = 2; i <= N; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N];
    }
};

class Solution4 {
public:
    int fib(int N) {
        if (N <= 1) 
            return N;
        int a = 0, b = 1;
        for (int i = 2; i <= N; ++i) {
            int sum = a + b;
            a = b;
            b = sum;
        }
        return b;
    }
};

int main()
{
    int n = 10;
    Solution1 s1;
    int res = s1.fib(n);
    cout<<res<<endl;

    n = 10;
    Solution2 s2;
    res = s2.fib(n);
    cout<<res<<endl;

    n = 10;
    Solution3 s3;
    res = s3.fib(n);
    cout<<res<<endl;

    n = 10;
    Solution4 s4;
    res = s4.fib(n);
    cout<<res<<endl;
}