#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        if(!g.size() || !s.size())
            return 0;
        int count = 0;
        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());
        int cookie=0,child=0;
        while (child < g.size() && cookie < s.size())
        {
            if (s[cookie] >= g[child])
            {
                child++;
                count ++;
            }
            cookie++;
        }
        return count;
    }
};

int main(){
	Solution solve;
	std::vector<int> g;
	std::vector<int> s;
	g.push_back(5);
	g.push_back(10);
	g.push_back(2);
	g.push_back(9);
	g.push_back(15);
	g.push_back(9);
	s.push_back(6);
	s.push_back(1);
	s.push_back(20);
	s.push_back(3);
	s.push_back(8);	
	printf("%d\n", solve.findContentChildren(g, s));
	return 0;
}
