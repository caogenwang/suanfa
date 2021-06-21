#include<iostream>
#include<vector>
using namespace std;

bool plane(vector<int> &arr,int max){
    sort(arr.begin(),arr.end());
    vector<int> dp(max+1,0);
    for (int i = 0; i < arr.size(); i++)
    {
        dp[arr[i]] ++;
    }
    for (int i = 0; i < dp.size()-1; i++)
    {
        if (dp[i] == 3 && dp[i+1] == 3)
        {
            return true;
        }
    }
    for (int i : dp)
        cout<<i<<" ";
    
    return false;
}

int main(){
    vector<int> arr{4,5,2,2,2,3,3,3};
    bool res = plane(arr,13);
    cout<<res<<endl;
}