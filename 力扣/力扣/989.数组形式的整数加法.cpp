#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {//大数运算的是会越界
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int num = 0;
        for (int i = 0; i < A.size(); i++)
        {
            num = num*10+A[i];
        }
        int sum = num + K;
        vector<int> vec;
        while (sum>0)
        {
            int tmp = sum%10;
            vec.push_back(tmp);
            sum = sum/10;
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};

class Solution2 {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> vec;
        while (K>0)
        {
            int tmp = K%10;
            vec.push_back(tmp);
            K = K/10;
        }
        reverse(A.begin(),A.end());
        int len = min(A.size(),vec.size());
        vector<int> res;
        int flag = 0;
        for (int i = 0; i < len; i++)
        {
            int sum = A[i] + vec[i] + flag;
            flag = 0;
            if (sum>10)
            {
                res.push_back(sum - 10);
                flag = 1;
            }
            else
            {
                res.push_back(sum);
            }
        }
        if (len > vec.size())
        {
            for (int i = len; i < A.size(); i++)
            {
                int sum = A[i] + flag;
                flag = 0;
                if (sum>10)
                {
                    res.push_back(sum - 10);
                    flag = 1;
                }
                else
                {
                    res.push_back(sum);
                }
            }  
        }
        else
        {
            for (int i = len; i < vec.size(); i++)
            {
                int sum = A[i] + flag;
                flag = 0;
                if (sum>10)
                {
                    vec.push_back(sum - 10);
                    flag = 1;
                }
                else
                {
                    res.push_back(sum);
                }
            } 
        }
        return vec;
    }
};

class Solution3 {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
		int n = A.size(), i = n - 1, carry = 0;
		while (K > 0 || carry > 0) 
        {
			int num = K % 10 + carry;
			if (i >= 0) 
                num += A[i];
			carry = num / 10;
			num %= 10;
			if (i >= 0) 
            {
				A[i] = num;
				--i;
			} 
            else 
            {
				A.insert(A.begin(), num);
			}
			K /= 10;
		}
		return A;
    }
};

class Solution4 {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        for (int i = (int)A.size() - 1; i >= 0; --i) 
        {
            res.insert(res.begin(), (A[i] + K) % 10);
            K = (A[i] + K) / 10;
        }
        while (K > 0) {
            res.insert(res.begin(), K % 10);
            K /= 10;
        }
        return res;
    }
};

int main()
{

}