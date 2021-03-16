
#include <iostream>
#include <vector>
#include <deque>
#include <numeric>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int> >& matrix) {

        for (int i = 0; i < matrix.size(); i++)
        {   
            vector<int> tmp;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                tmp.push_back(matrix[i][j]);
            }
            array.push_back(tmp);
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1;i<=row2;i++)
            sum += accumulate(array[i].begin()+col1,array[i].begin()+col2+1,0);
        return sum;
    }
private:
    vector<vector<int> > array;
};

int main()
{
    vector<vector<int> > matrix {
                                    {3, 0, 1, 4, 2},
                                    {5, 6, 3, 2, 1},
                                    {1, 2, 0, 1, 5},
                                    {4, 1, 0, 1, 7},
                                    {1, 0, 3, 0, 5}
                                    };
    NumMatrix *mat = new NumMatrix(matrix);
    int res = mat->sumRegion(1, 2, 2, 4);
    cout<<res<<endl;
}