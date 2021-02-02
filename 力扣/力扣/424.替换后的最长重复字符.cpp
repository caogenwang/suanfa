#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*medium*/
class Solution {//通不过
public:
    int characterReplacement(string s, int k) {
        int max = 1;
        for (int i = 0; i < s.length()-1; i++)
        {
            int j = i+1;
            while (j < s.length() && k != 0)
            {
                if(s[j] != s[i])
                    k--;
                j ++;
            }
            if((j - i + 1) > max)
                max = j - i + 1;
        }
        return max;
    }
};
/*
    这道题给我们了一个字符串，说我们有k次随意置换任意字符的机会，让我们找出最长的重复字符的字符串。
这道题跟之前那道 Longest Substring with At Most K Distinct Characters 很像，
都需要用滑动窗口 Sliding Window 来解。我们首先来想，如果没有k的限制，让我们求把字符串变成只有一
个字符重复的字符串需要的最小置换次数，那么就是字符串的总长度减去出现次数最多的字符的个数。如果加上k的限制，
我们其实就是求满足 (子字符串的长度减去出现次数最多的字符个数)<=k 的最大子字符串长度即可，搞清了这一点，
我们也就应该知道怎么用滑动窗口来解了吧。
    我们用一个变量 start 记录滑动窗口左边界，初始化为0，然后遍历字符串，
每次累加出现字符的个数，然后更新出现最多字符的个数，然后我们判断当前滑动窗口是否满足之前说的那个条件，
如果不满足，我们就把滑动窗口左边界向右移动一个，并注意去掉的字符要在 counts 里减一，直到满足条件，
我们更新结果 res 即可。需要注意的是，当滑动窗口的左边界向右移动了后，窗口内的相同字母的最大个数貌似可能会改变啊，
为啥这里不用更新 maxCnt 呢？这是个好问题，原因是此题让求的是最长的重复子串，maxCnt 相当于卡了一个窗口大小，
我们并不希望窗口变小，虽然窗口在滑动，但是之前是出现过跟窗口大小相同的符合题意的子串，缩小窗口没有意义，
并不会使结果 res 变大，所以我们才不更新 maxCnt
*/
class Solution2 {
public:
    int characterReplacement(string s, int k) {
        int res = 0, maxCnt = 0, start = 0;
        vector<int> counts(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            maxCnt = max(maxCnt, ++counts[s[i] - 'A']);//找到哪个字母出现次数最多
            while (i - start + 1 - maxCnt > k) {
                --counts[s[start] - 'A'];
                ++start;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};


int main()
{
    string s = "AABABBA";int k = 1;
    Solution so;
    int res = so.characterReplacement(s,k);
    cout<<res<<endl;
}