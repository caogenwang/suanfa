#include <stdio.h>

#include <string>
#include <map>
class Solution {
public:
    bool wordPattern(std::string pattern, std::string str) {
    	std::map<std::string, char> word_map;
    	char used[128] = {0};
    	std::string word;
    	int pos = 0;
    	str.push_back(' ');
    	for (int i = 0; i < str.length(); i++){
	    	if (str[i] == ' '){
	    		if (pos == pattern.length()){
	    			return false;
		    	}
	    		if (word_map.find(word) == word_map.end()){
	    			if (used[pattern[pos]]){//应该出现此前出现过的单词，但是当前单词不是，则返回
			    		return false;
			    	}
		    		word_map[word] = pattern[pos];//将word和字符做一个映射
		    		used[pattern[pos]] = 1;//标志位
		    	}
		    	else{
	    			if (word_map[word] != pattern[pos]){//如果映射和之前出现的不同则返回
			    		return false;
			    	}
	    		}
	    		word = "";
	    		pos++;
	    	}
	    	else{
	    		word += str[i];
	    	}
	    }
	    if (pos != pattern.length()){//单词个数和字符个数不相同
    		return false;
    	}
        return true;
    }
};

int main(){
	std::string pattern = "abba";
	std::string str = "dog cat cat dog";
	Solution solve;
	printf("%d\n", solve.wordPattern(pattern, str));
	return 0;
}
