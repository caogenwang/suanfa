#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<vector<int> > arrayCreate()
{
    vector<vector<int> > array;
    int row = 5;
    int col = 5;
    for (int i = 0; i < row; i++)
    { 
        vector<int> temp;
        temp.clear();
        for (int  j = 0; j < col; j++)
        {
            temp.push_back(i*j + j);
        }
        array.push_back(temp);
    }  
}

class Array
{
    public:
        Array(int num)
        {
            this->num = num;
            two_arr = arrayCreate();
            one_array = {2,3,1,0,2,5,3};
        }
        vector<vector<int> > arrayCreate()
        {
            vector<vector<int> > array;
            int row = num;
            int col = num;
            for (int i = 0; i < row; i++)
            { 
                vector<int> temp;
                temp.clear();
                for (int  j = 0; j < col; j++)
                {
                    temp.push_back(i*j + j);
                }
                array.push_back(temp);
            }  
        }
        bool find(int tar)
        {
            int row = two_arr.size();
            int col = two_arr[0].size();
            int start = two_arr[row-1][0];
            int i = row-1;
            int j = 0;
            while (i >= 0 && j < col)
            {
                if (tar < two_arr[i][j])
                {
                    i --;
                }
                else if(tar > two_arr[i][j])
                {
                    j ++;
                }
                else if(tar == two_arr[i][j])
                {
                    return true;
                }
                return false;
            }
        }
        int find_first_repeat_num()
        {
            std::set<int> s1;
            int len = one_array.size();
            std::pair<std::set<int>::iterator,bool> ret;
            for (int i = 0; i < len; i++)
            {
                ret = s1.insert(one_array[i]);
                if (ret.second == false)
                {
                    return one_array[i];
                }
            }
            return 0;
        }
        int find_the_longest_repeat_num()
        {
            std::multiset<int> mset;
            int len = one_array.size();
            for (int i = 0; i < len; i++)
            {
                mset.insert(one_array[i]);
            }
            int maxNum = 0;
            int maxCount = 0;

            for (int i = 0; i < len; i++)
            {
                int count = mset.count(one_array[i]);

                if (count > maxCount)
                {
                    maxCount = count;
                    maxNum = one_array[i];
                }
                
            }
            return maxNum;
        }
        vector<int> multiply(const vector<int>& A) 
        {
            vector<int> B;
            int res = 1;
            for (int  i = 0; i < A.size(); i++)
            {
                for (int j = 0; j < A.size(); j++)
                {
                    if(i != j)
                    {
                        res *= A[i];
                    }
                    
                }
                B.push_back(res);
            }
            return B;
        }
    private:
        int num;
        vector<vector<int> > two_arr;
        vector<int> one_array;
};

int main(int argc,char**argv)
{   
    cout<<argc<<endl;
    Array *array = new Array(5);
    bool result = array->find(20);
    cout<<result<<endl;
    return 0;
}