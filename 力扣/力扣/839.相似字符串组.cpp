#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int res = 0;
        unordered_set<string> visited;
        for (string str : A) {
			if (visited.count(str)) continue;
			++res;
			helper(A, str, visited);
		}
		return res;
   	}
   	void helper(vector<string>& A, string& str, unordered_set<string>& visited) {
   		if (visited.count(str)) return;
   		visited.insert(str);
   		for (string word : A) {
   			if (isSimilar(word, str)) {
   				helper(A, word, visited);
   			}
   		}
   	}
   	bool isSimilar(string& str1, string& str2) {
   		for (int i = 0, cnt = 0; i < str1.size(); ++i) {
   			if (str1[i] == str2[i]) continue;
   			if (++cnt > 2) return false;
   		}
   		return true;
   	}
};

int main()
{

}