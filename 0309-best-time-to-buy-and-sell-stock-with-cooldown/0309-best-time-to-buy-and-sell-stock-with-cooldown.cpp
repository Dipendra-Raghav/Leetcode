class Solution {
public:
    int solve(vector<int>& prices,int n,int i,int t, vector<vector<int>> &dp)
    {
        //base condition
        if(i>=n )
        return 0;
        
        if(dp[i][t]!=-1)
        return dp[i][t];
        int p=INT_MIN;
        int b=INT_MIN;
        int s=INT_MIN;
        if(t==0)
        {
            //pass
            p=solve(prices,n,i+1,t,dp);
            //buy
            b=-prices[i]+solve(prices,n,i+1,1,dp);
            
        }
        else
        {
            //pass
            p=solve(prices,n,i+1,t,dp);
            //sell
            s=prices[i]+solve(prices,n,i+2,0,dp);
            
            
        }
        return dp[i][t]=max(p,max(b,s));
        
        
    }
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return solve(prices,n,0,0,dp);
        
    }
};