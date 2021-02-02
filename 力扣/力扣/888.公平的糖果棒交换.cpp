
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <numeric>
using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(),A.end(),0);
        int sumB = accumulate(B.begin(),B.end(),0);
        vector<int> tmp;
        vector<int> res;
        for(int i = 0;i<A.size();i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                if ((sumA-A[i]+B[j]) == (sumB-B[j]+A[i]))
                {
                    tmp.push_back(A[i]);
                    tmp.push_back(B[j]);
                    break;
                }
            }
        }
        res.push_back(tmp[0]);
        res.push_back(tmp[1]);
        return res;
    }
};

class Solution2 {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(),A.end(),0);
        int sumB = accumulate(B.begin(),B.end(),0);
        int mid = (sumA+sumB)/2;
        unordered_set<int> Bset(A.begin(), A.end());
        for(int i = 0;i<A.size();i++)
        {
            int left = mid - (sumA - A[i]);
            if (Bset.count(left) && mid == (sumB - left + A[i]))
                return {A[i],left};
        }
        return {};
    }
};

class Solution3 {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		int diff = (accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) / 2;
		unordered_set<int> st(A.begin(), A.end());
		for (int num : B) {
			if (st.count(num + diff)) 
                return {num + diff, num};
		}
		return {};
    }
};

class Solution4 {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        bitset<100001> setb;
        int suma = 0, sumb = 0;
        for (int n: A) {
            suma += n;
        }
        for (int n: B) {
            setb[n] = true;
            sumb += n;
        }
        const int aver = (suma+sumb) / 2;
        for (int n: A) {
            int diff = aver - (suma - n);
            if (diff >= 0 and diff <= 100000 and setb[diff]  ) {
                return {n, diff};
            }
        }
        return {};
    }
};

int main()
{
    vector<int> A{1,1};
    vector<int> B{2,2};
    Solution2  so;
    vector<int> res = so.fairCandySwap(A,B);
    for (auto &&i : res)
        cout<<i<<endl;
    
}