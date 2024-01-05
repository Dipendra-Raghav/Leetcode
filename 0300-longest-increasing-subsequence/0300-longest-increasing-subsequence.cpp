class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            int mx=0;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i])
                    mx=max(mx,dp[j]);
            }
            dp[i]=mx+1;
        }
       // for(int i=0;i<dp.size();i++)cout<<dp[i]<<" ";
        sort(dp.begin(),dp.end());
        return dp[dp.size()-1];
        
    }
};