#include <iostream>
#include<vector>
using namespace std;
/*
    points = [[10,16],[2,8],[1,6],[7,12]]
    输出：2
    解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球

*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int> >& points) {
        if (points.size() == 0){
	    	return 0;
	    }

        int count  = 1;
        int start = points[0][0];
        int end = points[0][1];
        for(int i = 1;i < points.size();i ++){
            vector<int> point = points[i];
            if (end >= point[1])
            {
                start = max(start,point[0]);
                end = point[1];
            }
            else if(start < point[1])
            {
                start = max(start,point[0]);
            }
            else{
                count ++;
                start = point[0];
                end = point[1];
            }
        }
        return count;
    }
};


class Solution2 {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
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

int main(){

}