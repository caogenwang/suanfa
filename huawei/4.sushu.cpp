#include<vector>
#include<iostream>
using namespace std;

bool is_sushu(int num)
{
    for (int i = 3; i < num / 2; i++)
        if (num%i == 0)
            return false;
    return true;
}
vector<int> sushu(int num)
{
    int min = INT_MAX;
    int a1 = -1;
    int a2 = -1;
    vector<int> res(2,-1);
    for (int i = num / 2 - 1; i > 0; i--)
    {
        
        int left = num - i;
        // cout<<i<<" "<<left<<endl;
        if((i%2 != 0) && (left%2 != 0)
            && is_sushu(i) && is_sushu(left))
        {
            if(min > left - i)
            {
                min = left - i;
                a1 = i;
                a2 = left;
            }
        }
    }
    res[0] = a1;
    res[1] = a2;
    return res;
}

int main()
{
    vector<int> res = sushu(200000);
    cout<<res[0]<<" "<<res[1]<<endl;
}