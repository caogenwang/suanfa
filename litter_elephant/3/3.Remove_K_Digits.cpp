
#include <stdio.h>

#include <string>
#include <vector>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
    	std::vector<int> S;
    	std::string result = "";
    	for (int i = 0; i < num.length(); i++)
		{
	    	int number = num[i] - '0';
	    	while(S.size() != 0 && S[S.size()-1] > number && k > 0){//S[S.size()-1]模拟栈顶
	    		S.pop_back();
	    		k--;
	    	}
	    	if (number != 0 || S.size() != 0){//如果size等于0，再压入0是没有意义的
	    		S.push_back(number);
	    	}
	    }
	    while(S.size() != 0 && k > 0){//剩余的数字，在前边的过程中，已经将所有的数字压入栈中，
    		S.pop_back();            //如果k不为0，则说明已经按照从小到大排列好了，然后再从尾开始删除
    		k--;
    	}
	    for (int i = 0; i < S.size(); i++){
    		result.append(1, '0' + S[i]);
    	}
    	if (result == ""){
	    	result = "0";
	    }
    	return result;
    }
};

int main(){
	Solution solve;
	std::string result = solve.removeKdigits("1432219", 3);
	printf("%s\n", result.c_str());
	std::string result2 = solve.removeKdigits("100200", 1);
	printf("%s\n", result2.c_str());
	return 0;
}
