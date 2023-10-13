class Solution {
public:
    int solve(vector<int> &cost,int i,vector<int> &dp )
    {
        if(i==cost.size())return 0;
        if(dp[i]!=-1)return dp[i];
       
        int a=INT_MAX;
        int b=INT_MAX;
        if(i+1<=cost.size())
        a=cost[i]+solve(cost,i+1,dp);
        if(i+2<=cost.size())
        b=cost[i]+solve(cost,i+2,dp);
        return dp[i]=min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return min(solve(cost,0,dp),solve(cost,1,dp));
        
    }
};