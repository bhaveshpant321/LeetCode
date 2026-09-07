class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // we can check for each denomination starting from zero upto current amount
        // unbounded, so loop can go normally
        vector<int> dp(amount+1, amount+1);
        dp[0]= 0;

        // number of ways to make each denomination
        for(int i=1; i<amount+1; i++){    
            for(int c: coins){
                if(i-c>= 0){    // only valid iff current coin value is not more than the desired amount
                    dp[i]= min(dp[i], 1+ dp[i-c]);
                }
            }
        }
        return dp[amount]> amount? -1: dp[amount];
    }
};