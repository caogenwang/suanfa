#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <list>
#include <queue>
using namespace std;

typedef struct _List
{
    int val;
    struct _List *next;
    struct _List *pre;
}List;
//编写一个函数，其作用是将输入的字符串反转过来
class Solution {
public:
    string reverseString(string s) {
        string res(s.rbegin(),s.rend());//这里s.crbegin()和s.crend()也可以
        return res;
        
    }
};
char*reverseString(char* str)
 {
     int count = 0;
        while (str[count] != '\0')
        {
            count++;
        }
        char string[count];
        for(int i=0;i<count;i++)
        {
            string[i] = str[count - i];
        }
    return string;
 }
int countSegments(string s) 
{
    int res = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') continue;
        ++res;
        while (i < n && s[i] != ' ') ++i;
    }
    return res;
}

//字符串相加 leetcode 415
string addStrings(string num1, string num2)
{
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    string result = "";
    int carry = 0;
    while(i >= 0 || j >= 0)
    {
        if(i >= 0)
        {
            carry += num1[i] - '0';
        }
        if(j >= 0)
        {
            carry += num2[j] - '0';
        }
        result +=  (char)(carry % 10 - '0');
        carry /= 10;
        i --;
        j --;
    }
    if(carry == 1)
    {
        result += '1';
    }
    string s(result.rbegin(),result.rend());
    return s;
}

//最长公共前缀 leetcode14
string longestCommonPrefix(vector<string>& strs) 
{
    string prefix = "";
    string first = strs[0];
    int size = strs.size();
    if(size <= 0)
        return prefix;
    
    int length = first.size();
    for (int i = 0; i < length; i++)
    {
        bool common = false;
        for (int j = 0; j < size && strs[j].size() > i; j++)
        {
            if (strs[j][i] != first[i])
            {
                common = true;
            }
        }
        if (common)
        {
            return first.substr(0,i);
            break;
        }
    }
}
//无重复字符的最长子串 leetcode 03
/*
那么如何判断新字符是否已经在子串中出现过呢？
我们可以使用Map<char, bool>，它的原理是：将每个字符作为一个节点存在一颗二叉树中，
尝试插入新字符的节点，如果出现冲突（树中已经有相同字符的节点），则表明新字符已经出现过。
每次判断的复杂度为log(m)，m为子串的最大长度。
在进行子串左端点右移的时候，要记得将被移出的字符从map种删掉。
还有一种更高效的查找方法：哈希表。在这道题使用哈希表有天然的优势：char的范围是已知的、
较小的——[0, 255]（unsigned char）。
那么就可以直接用一个bool[256]数组来存储每一种字符是否已出现。
在进行子串左端点右移的时候，要记得将被移出的字符重新标记为未访问。

以上两种方法在进行子串左端点右移的时候都要进行重置操作。
为了避免它，我们不存储bool(是否出现过)，而是存储int(上次出现的下标)。详见下面的代码部分。

*/
int lengthOfLongestSubstring(string s) 
{
    map<char, int> last_appear_index;
    int sub_string_start = 0;
    int max_length = 0;
    map<char,int>::iterator it;
    for (int i = 0; i < s.length; i++)
    {
        it = last_appear_index.find(s[i]);
        if (it != last_appear_index.end() && it->second >= sub_string_start)
        {
            sub_string_start = it->second + 1;
        }
        last_appear_index[s[i]] = i;
        max_length = max(max_length,i-sub_string_start+1);
    }
    return max_length;
}
int lengthOfLongestSubstring(string s)
{
    int ret = 0;		
	map<char, int> m;	//map键-值对，添加的元素如果没有的话就会初始化		
	int start = 1;			
	for (int i = 1; i <= s.length(); i++)		
    {			
        char c = s[i - 1];			
        if (m[c] >= start)	//如果遇到相同的元素则把start放到元素的后面
        { 				
            start = m[c] + 1;				
            m[c] = i;			
        }			
        else			
        //否则更新长度，长度是通过i（尾部）和start（头部）来决定			
        {				
            m[c] = i;				
            ret = max(ret, i - start + 1);//更新:大于目前存储的最大元素			
        } 		
    }		
	return ret;	
}