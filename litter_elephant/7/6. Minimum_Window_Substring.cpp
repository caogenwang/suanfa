
#include <stdio.h>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
	bool is_window_ok(int map_s[], int map_t[], std::vector<int> &vec_t){
    	for (int i = 0; i < vec_t.size(); i++){
    		if (map_s[vec_t[i]] < map_t[vec_t[i]]){//判断是否是一个窗口了
		    	return false;
		    }
	    }
	    return true;
    }
public:
    std::string minWindow(std::string s, std::string t) {
        const int MAX_ARRAY_LEN = 128;
        int map_t[MAX_ARRAY_LEN] = {0};
        int map_s[MAX_ARRAY_LEN] = {0};
        std::vector<int> vec_t;
        for (int i = 0; i < t.length(); i++){
        	map_t[t[i]]++;//字符的ASSIC码直接当key
        }
        for (int i = 0; i < MAX_ARRAY_LEN; i++){
        	if (map_t[i] > 0){
	        	vec_t.push_back(i);
	        }
        }
        
        int window_begin = 0;
        std::string result;
        for (int i = 0; i < s.length(); i++){
        	map_s[s[i]]++;
        	while(window_begin < i){
        		char begin_ch = s[window_begin];
	        	if (map_t[begin_ch] == 0){//map_t中存放着每个字符的个数
	        		window_begin++;
	        	}
	        	else if	(map_s[begin_ch] > map_t[begin_ch]){//出现重复的了
	        		map_s[begin_ch]--;
	        		window_begin++;
	        	}
	        	else{
	        		break;
	        	}
	        }
	        if (is_window_ok(map_s, map_t, vec_t)){//如果一个窗口则记录下来
        		int new_window_len = i - window_begin + 1;
        		if (result == "" || result.length() > new_window_len){
		        	result = s.substr(window_begin, new_window_len);
				}
        	}
        }
        return result;
    }
};
class Solution1 {
public:
    string minWindow(string S, string T) {//在S中包含T的最小字符串
        string res = "";
        int left = 0;
        int cnt = 0;
        int length = S.length();
        int minLen = INT_MAX;
        std::map<char,int> letterCnt;
        for(char c:T)//记录要包含的字符
            letterCnt[c] = letterCnt[c] + 1;
        for(int i=0;i<length;i++)
        {
            if(--letterCnt[S[i]] >= 0)//S中存在T中的字符
                cnt++;//记录包含的字符个数
            while (cnt == T.size())//letterCnt中包含所有T中的字符了
            {
                if(minLen > i - left + 1)
                {
                    minLen = i - left + 1;
                    res = S.substr(left,minLen);
                }
                if(++letterCnt[S[i]]>0)//当前节点是存在T中的
                    cnt--;
                left++;
            }
        }
        return res;
    }
};

int main(){
	
	Solution solve;
	std::string result = solve.minWindow("ADOBECODEBANC", "ABC");
	printf("%s\n", result.c_str());
	result = solve.minWindow("MADOBCCABEC", "ABCC");
	printf("%s\n", result.c_str());
	result = solve.minWindow("aa", "aa");
	printf("%s\n", result.c_str());
	
	return 0;	
}
