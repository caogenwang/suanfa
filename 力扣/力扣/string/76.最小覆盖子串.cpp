#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:

    bool is_window_ok(int map_s[], int map_t[], std::vector<int> &vec_t){
    	for (int i = 0; i < vec_t.size(); i++){
    		if (map_s[vec_t[i]] < map_t[vec_t[i]]){
		    	return false;
		    }
	    }
	    return true;
    }

    string minWindow(string s, string t) {
        const int MAX_ARRAY_LEN = 128;
        int map_s[MAX_ARRAY_LEN] = {0};
        int map_t[MAX_ARRAY_LEN] = {0};
        std::vector<int> vec_t;
        for (int i = 0; i < t.length(); i++){
        	map_t[t[i]]++;
        }
        for (int i = 0; i < MAX_ARRAY_LEN; i++){
        	if (map_t[i] > 0){
	        	vec_t.push_back(i);
	        }
        }
        int window_begin = 0;
        std::string result;

        for (int i = 0; i < s.length(); i++)
        {
        	map_s[s[i]]++;
        	while(window_begin < i){
        		char begin_ch = s[window_begin];
	        	if (map_t[begin_ch] == 0){
	        		window_begin++;
	        	}
	        	else if	(map_s[begin_ch] > map_t[begin_ch]){
	        		map_s[begin_ch]--;
	        		window_begin++;
	        	}
	        	else{
	        		break;
	        	}
	        }
	        if (is_window_ok(map_s, map_t, vec_t)){
        		int new_window_len = i - window_begin + 1;
        		if (result == "" || result.length() > new_window_len){
		        	result = s.substr(window_begin, new_window_len);
				}
        	}
        }
        return result;
    }   
};

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> letterCnt(128, 0);
        int left = 0, cnt = 0, minLeft = -1, minLen = INT_MAX;
        for (char c : t) 
            ++letterCnt[c];

        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) 
                ++cnt;
            while (cnt == t.size()) 
            {
                if (minLen > i - left + 1) 
                {
                    minLen = i - left + 1;
                    minLeft = left;
                }
                if (++letterCnt[s[left]] > 0) 
                    --cnt;
                ++left;
            }
        }
        return minLeft == -1 ? "" : s.substr(minLeft, minLen);
    }
};


int main()
{
    string s = "ADOBECODEBANC"; 
    string t  = "ABC";

    Solution so;
    string s2 = so.minWindow(s,t);
    cout<<s2<<endl;
}