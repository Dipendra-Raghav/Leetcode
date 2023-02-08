class Solution {
public:
    int solve(vector<int>& nums,int i,int n,vector<int> &dp)
    {
        //base condition
        if(i==n)
        {
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];
        int ans=100000;
       
        for(int j=1;j<=nums[i];j++)
        {
            if(i+j<=n)
            {
                ans=min(ans,1+solve(nums,i+j,n,dp));
            }
            else
                continue;
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
       return  solve(nums,0,n-1,dp);
        
    }
};