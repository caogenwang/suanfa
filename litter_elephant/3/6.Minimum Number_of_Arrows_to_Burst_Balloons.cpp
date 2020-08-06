#include <stdio.h>

#include <algorithm>
#include <vector>

bool cmp(const std::pair<int, int> &a, const std::pair<int ,int> &b) {
    return a.first < b.first;
}

class Solution {
public:
    int findMinArrowShots(std::vector<std::pair<int, int> >& points) {
    	if (points.size() == 0){
	    	return 0;
	    }
    	std::sort(points.begin(), points.end(), cmp);
    	int shoot_num = 1;
    	int shoot_begin = points[0].first;
    	int shoot_end = points[0].second;
    	for (int i = 1; i < points.size(); i++){//更新交叉区域，尽可能一次射击更多的气球。
	    	if (points[i].first <= shoot_end){
	    		shoot_begin = points[i].first;
    			if (shoot_end > points[i].second){
			    	shoot_end = points[i].second;
			    }
	    	}
	    	else{//下一个没有交集了，则需要安排一个射击手了
	    		shoot_num++;
	    		shoot_begin = points[i].first;
	    		shoot_end = points[i].second;
	    	}
	    }
	    return shoot_num;
    }
};

int main(){
	std::vector<std::pair<int, int> > points;
	points.push_back(std::make_pair(10, 16));
	points.push_back(std::make_pair(2, 8));
	points.push_back(std::make_pair(1, 6));
	points.push_back(std::make_pair(7, 12));	
	Solution solve;
	printf("%d\n", solve.findMinArrowShots(points));
	return 0;
}
