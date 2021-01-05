#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <map>
using namespace std;
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };


class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int length = points.size();
        int ret = 0;
        if(length == 0)
            return 0;
        if(length == 1)
            return 1;
        
        for (int i = 0; i < length; i++)
        {
            //一轮下来就是以当前点为起点的个数最大的点
            int curmax = 1;
            map<double,int> mp;
            int vcnt = 0;//垂直斜率
            int duplicate = 0;//重复点

            for (int j = i+1; j < length; j++)
            {
                double x1 = points[j].x - points[j].x;
                double y1 = points[j].y - points[j].y;
                if (x1 == 0 && y1 == 0)
                {
                    duplicate++;
                }
                else if(x1 == 0)
                {
                    if(vcnt==0)
                            vcnt = 2;
                        else
                            vcnt ++;
                    curmax = max(vcnt,curmax);
                }
                else
                {
                    double k = y1 / x1;
                    if(mp[k] == 0)
                        mp[k] = 2;
                    else
                        mp[k]++;
                    curmax = max(mp[k],curmax);
                }
            }
            ret = max(ret,curmax+duplicate);
        }
        return ret;
    }
};

int main(int argc,char**argv)
{
    return 0;
}