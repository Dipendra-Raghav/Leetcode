class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int i,int j,int prev, vector<vector<int>> &dp)
    {
        if(i>=nums1.size() || j>=nums2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(nums1[i]==nums2[j] && j>prev)
        {
            prev=j;
            return dp[i][j] =1+solve(nums1,nums2,i+1,j+1,prev,dp);
        }
        else
        {
            return dp[i][j]=max(solve(nums1,nums2,i,j+1,prev,dp),solve(nums1,nums2,i+1,j,prev,dp));
        }
        
        
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));
        return solve(nums1,nums2,0,0,-1,dp);
        
    }
};