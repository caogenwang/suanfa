#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> m;
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++duplicate; continue;
                } 
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int d = gcd(dx, dy);
                ++m[{dx / d, dy / d}];
            }
            res = max(res, duplicate);
            for (auto it = m.begin(); it != m.end(); ++it) {
                res = max(res, it->second + duplicate);
            }
        }
        return res;
    }
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};
class Solution2 {
public:
    int maxPoints(vector<vector<int> >& points) {
        if (points.size()<=2)
            return points.size();
        
        int count = points.size();
        int max = 2;
        int nums = 2;
        for (int i = 0; i < count; i++)
        {
            for (int j = i+1; j < count; j++)
            {
                nums = 2;
                for (int m = j+1; m < count; m++)
                {
                    long int x1 = (points[j][0] - points[i][0])*(points[m][1] - points[i][1]);
                    long int x2 = (points[m][0] - points[i][0])*(points[j][1] - points[i][1]);
                    if(x1 == x2)
                        nums ++;
                    if(max < nums) max = nums;
                }
            }
        }
        return max;
    }
};

int main(){
 vector<vector<int> > points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
 Solution2 s;
 int count = s.maxPoints(points);
 std::cout<<count<<std::endl;
 return 0;
}