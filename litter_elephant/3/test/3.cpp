#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::string res;
        std::vector<char> stack;
        int j=1;
        stack.push_back(num.at(0));
        while (j<num.length())
        {
            if(stack.size() != 0 && num.at(j) < stack.back() && k>0)
            {
                stack.pop_back();
                k--;
            }
            if (num.at(j) != '0' || stack.size() != 0){//如果size等于0，再压入0是没有意义的
	    		stack.push_back(num.at(j));
	    	}
            j++;
        }
        while(stack.size() != 0 && k > 0){//剩余的数字，在前边的过程中，已经将所有的数字压入栈中，
    		stack.pop_back();            //如果k不为0，则说明已经按照从小到大排列好了，然后再从尾开始删除
    		k--;
    	}
        for (int i = 0; i < stack.size(); i++){
    		res.append(1, stack[i]);
    	}
    	if (res == ""){
	    	res = "0";
	    }

        return res;
    }
};


int main()
{
    Solution solve;
	std::string result = solve.removeKdigits("1432219", 3);
	printf("%s\n", result.c_str());
	std::string result2 = solve.removeKdigits("100200", 1);
	printf("%s\n", result2.c_str());
	return 0;
}