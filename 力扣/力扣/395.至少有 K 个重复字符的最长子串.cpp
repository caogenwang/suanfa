#include <iostream>
#include <vector>
#include <deque>
using namespace std;
/*
    我们一个字符串s和一个正整数k，让求一个最大子字符串并且每个字符必须至少出现k次。
    作为 LeetCode 第三次编程比赛的压轴题目，博主再一次没有做出来，虽然难度标识只是 Medium。
    后来在网上膜拜学习了大神们的解法，发现当时的没做出来的原因主要是卡在了如何快速的判断某一个
    字符串是否所有的字符都已经满足了至少出现k次这个条件，虽然博主也用 HashMap 建立了字符和其
    出现次数之间的映射，但是如果每一次都要遍历 HashMap 中的所有字符看其出现次数是否大于等于k，
    未免有些不高效。而用 mask 就很好的解决了这个问题，由于字母只有 26 个，而整型 mask 有 32 位，
    足够用了，每一位代表一个字母，如果为1，表示该字母不够k次，如果为0就表示已经出现了k次，这种思路
    真是太聪明了，隐约记得这种用法在之前的题目中也用过，但是博主并不能举一反三( 沮丧脸:( )，
    还得继续努力啊。遍历字符串，对于每一个字符，都将其视为起点，然后遍历到末尾，增加 HashMap 
    中字母的出现次数，如果其小于k，将 mask 的对应位改为1，如果大于等于k，将 mask 对应位改为0。
    然后看 mask 是否为0，是的话就更新 res 结果，然后把当前满足要求的子字符串的起始位置j保存到 
    max_idx 中，等内层循环结束后，将外层循环变量i赋值为 max_idx+1，继续循环直至结束
*/
//先找一个最小的可以满足的，然后扩大窗口
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0, i = 0, n = s.size();
        while (i + k <= n) {
            int m[26] = {0}, mask = 0, max_idx = i;
            for (int j = i; j < n; ++j) {
                int t = s[j] - 'a';
                ++m[t];
                if (m[t] < k)
                    mask |= (1 << t);
                else 
                    mask &= (~(1 << t));
                if (mask == 0) {
                    res = max(res, j - i + 1);
                    max_idx = j;
                }
            }
            i = max_idx + 1;
        }
        return res;
    }
};

class Solution2 {
public:
    int longestSubstring(string s, int k) {
        int res = 0, n = s.size();
        for (int cnt = 1; cnt <= 26; ++cnt) {
            int start = 0, i = 0, uniqueCnt = 0;
            vector<int> charCnt(26);
            while (i < n) {
                bool valid = true;
                if (charCnt[s[i++] - 'a']++ == 0) ++uniqueCnt;
                while (uniqueCnt > cnt) {
                    if (--charCnt[s[start++] - 'a'] == 0) --uniqueCnt;
                }
                for (int j = 0; j < 26; ++j) {
                    if (charCnt[j] > 0 && charCnt[j] < k) valid = false;
                }
                if (valid) res = max(res, i - start);
            }
        }    
        return res;
    }
};
/*
    这里使用了一个变量 max_idx，是用来分割子串的，实现开始统计好了字符串s的每个字母出现的次数，
    然后再次遍历每个字母，
    若当前字母的出现次数小于k了，则从开头到前一个字母的范围内的子串可能是
    满足题意的，还需要对前面的子串进一步调用递归，用返回值来更新当前结果 res，此时变量 ok 标记为 
    false，表示当前整个字符串s是不符合题意的，因为有字母出现次数小于k，此时 max_idx 更新为 i+1，
    表示再从新的位置开始找下一个出现次数小于k的字母的位置，可以对新的范围的子串继续调用递归。
    当 for 循环结束后，若 ok 是 true，说明整个s串都是符合题意的，直接返回n，否则要对 [max_idx, n-1] 
    范围内的子串再次调用递归，因为这个区间的子串也可能是符合题意的，还是用返回值跟结果 res 比较，
    谁大就返回谁
*/
class Solution3 {
public:
    int longestSubstring(string s, int k) {
        int n = s.size(), max_idx = 0, res = 0;
        int m[128] = {0};
        bool ok = true;
        for (char c : s)
            ++m[c];
        for (int i = 0; i < n; ++i) 
        {
            if (m[s[i]] < k) {
                res = max(res, longestSubstring(s.substr(max_idx, i - max_idx), k));
                ok = false;
                max_idx = i + 1;
            }
        }
        return ok ? n : max(res, longestSubstring(s.substr(max_idx, n - max_idx), k));
    }
};

int main()
{
    string s = "aaabb";
    int k = 3;
    Solution so;
    int res = so.longestSubstring(s,k);
    cout<<res<<endl;
}