#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;
/*easy*/
class Solution {
public:
    bool checkStraightLine(vector<vector<int> >& coordinates) {
        if (coordinates.size() <=2)
        {
            return true;
        }

        int x = coordinates[1][0] - coordinates[0][0];
        int y = coordinates[1][1] - coordinates[0][1];
        for (int i = 2; i < coordinates.size(); i++)
        {
            int t1 = y*(coordinates[i][0]-coordinates[0][0]);
            int t2 = x*(coordinates[i][1]-coordinates[0][1]);
            if (t1 != t2)
            {
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool checkStraightLine(vector<vector<int> > &coordinates) {
        int deltaX = coordinates[0][0], deltaY = coordinates[0][1];
        int n = coordinates.size();
        for (int i = 0; i < n; ++i) {
            coordinates[i][0] -= deltaX;
            coordinates[i][1] -= deltaY;
        }
        int A = coordinates[1][1], B = -coordinates[1][0];
        for (int i = 2; i < n; ++i) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if (A * x + B * y != 0) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<int> >coordinates{{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    Solution s;
    bool res = s.checkStraightLine(coordinates);
    cout<<res<<endl;
}

