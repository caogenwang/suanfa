#include<iostream>
#include<vector>
using namespace std;

int coinChange(std::vector<int> &coins,int amount)
{
    vector<int> dp(amount+1,-1);
    dp[0]=0;
    for(int i=1;i<=amount;i++){
        for (int j = 0; j < coins.size(); j++){
            if(i-coins[j]>=0 && dp[i-coins[j]] != -1){
                if(dp[i] == -1 || dp[i]>dp[i-coins[j]]+1)
                    dp[i]= dp[i-coins[j]]+1;
            }
        }
    }
    return dp[3];
}

int main(){	
	std::vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	coins.push_back(7);
	coins.push_back(10);	
	for (int i = 14; i<= 14; i++){
		printf("dp[%d] = %d\n", i, coinChange(coins, i));
	}
	return 0;
}