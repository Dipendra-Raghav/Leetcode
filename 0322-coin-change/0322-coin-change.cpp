class Solution {
public:
    
    int solve(vector<int>& coins, int amount,vector<int> &dp)
    {
        if(amount<0)return INT_MAX;
        if(amount==0)return 0;
        if(dp[amount]!=-1)return dp[amount]; 
        int mx=INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            int a=solve(coins, amount-coins[i],dp);
           if(a==INT_MAX)continue;
            else   
           mx=min(mx,1+a);
        }
        return dp[amount]=mx;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int p=solve(coins, amount,dp);
        return p==INT_MAX ? -1 : p; 
       
        
    }
};