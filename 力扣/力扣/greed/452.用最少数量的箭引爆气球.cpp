#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int> >& points) {
        if (points.size() == 0){
	    	return 0;
	    }
        sort(points.begin(), points.end());
        int nums = 1;;
        int left = points[0][0];
        int right = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {            
            if(points[i][0] <= right)
            {
                left = points[i][0];               
                if (right > points[i][1])
                {
                    right = points[i][1];
                }
            }
            else
            {
                nums ++;
                left = points[i][0];
                right = points[i][1];
            }
                 
        }
        return nums;
    }
};

class Solution3 {//通过
public:
    int findMinArrowShots(vector<vector<int> >& points) {
        if (points.size() == 0){
	    	return 0;
	    }
        sort(points.begin(), points.end());
    	int shoot_num = 1;
    	int shoot_begin = points[0][0];
    	int shoot_end = points[0][1];
    	for (int i = 1; i < points.size(); i++){
	    	if (points[i][0] <= shoot_end){
	    		shoot_begin = points[i][0];
    			if (shoot_end > points[i][1]){
			    	shoot_end = points[i][1];
			    }
	    	}
	    	else{
	    		shoot_num++;
	    		shoot_begin = points[i][0];
	    		shoot_end = points[i][1];
	    	}
	    }
	    return shoot_num;
    }
};

bool cmp(const std::pair<int, int> &a, const std::pair<int ,int> &b) {
    return a.first < b.first;
}
class Solution2 {
public:
    int findMinArrowShots(std::vector<std::pair<int, int> >& points) {
    	if (points.size() == 0){
	    	return 0;
	    }
    	std::sort(points.begin(), points.end(), cmp);
    	int shoot_num = 1;
    	int shoot_begin = points[0].first;
    	int shoot_end = points[0].second;
    	for (int i = 1; i < points.size(); i++){
	    	if (points[i].first <= shoot_end){
	    		shoot_begin = points[i].first;
    			if (shoot_end > points[i].second){
			    	shoot_end = points[i].second;
			    }
	    	}
	    	else{
	    		shoot_num++;
	    		shoot_begin = points[i].first;
	    		shoot_end = points[i].second;
	    	}
	    }
	    return shoot_num;
    }
};


int main()
{
    vector<vector<int> >points{{10,16},{2,8},{1,6},{7,12}};
    vector<vector<int> >points2{{1,2},{2,3},{3,4},{4,5}};
    vector<vector<int> >points3{{1,2}};
    vector<vector<int> >points4{{2,3},{2,3}};
    Solution s;

    int res = s.findMinArrowShots(points2);
    cout<<res<<endl;
}