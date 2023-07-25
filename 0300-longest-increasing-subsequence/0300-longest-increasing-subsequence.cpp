class Solution {
public:
    int solve(vector<int>& nums,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=nums.size())return 0;
        if(dp[i][j+1]!=-1)return dp[i][j+1];
        //include
        int a=0;
        if(j==-1 || nums[i]>nums[j])
            a=1+solve(nums,i+1,i,dp);
        //exclude
        int b=solve(nums, i+1, j,dp);
        
        return dp[i][j+1]=max(a,b);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+2,vector<int>(nums.size()+2,-1));
        return solve(nums,0, -1,dp);
        
    }
};