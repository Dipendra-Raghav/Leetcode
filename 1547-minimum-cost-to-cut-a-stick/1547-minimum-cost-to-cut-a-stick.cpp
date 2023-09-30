class Solution {
public:
    int solve(vector<int> &cuts,int i,int j, vector<vector<int>> &dp)
    {
        if(i>j)return 0;
        int res=INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i;k<=j;k++)
        {
            int ans=cuts[j+1]-cuts[i-1]+solve(cuts,i,k-1,dp)+solve(cuts,k+1,j,dp);
            res=min(res,ans);
        }
        return dp[i][j]=res;
        
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),-1));
        
      
        return solve(cuts,1,cuts.size()-2,dp);
        
    }
};