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
        std::sort(points.begin(),points.end(),cmp);
        int shooter = 1;
        int left = points[0].first;
        int right = points[0].second;

        for(int i=0;i<points.size();i++)
        {
            int left_tmp = points[1].first;
            int right_tmp = points[1].second;

            if (left < left_tmp)
            {
                
            }
            
        }

        return shooter;
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

