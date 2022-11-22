class Solution {
public:
    int solve(vector<int> &arr,int n,vector<int> &dp)
    {
        if(n==0)
            return 0;
        if(n<0)
            return INT_MAX;
        if(dp[n]!=-1)
            return dp[n];
        
        int mini=INT_MAX;
        
        for(int i=0;i<arr.size();i++)
        {
            int ans=solve(arr,n-arr[i],dp);
            if(ans!=INT_MAX)
            {
                mini=min(mini,1+ans);
            }
        }
        dp[n]= mini;
        return dp[n];
    }
    int numSquares(int n) {
        int i=1;
        vector<int> arr;
        vector<int> dp(n+1,-1);
        while((i*i)<=n)
        {
            arr.push_back(i*i);
            i++;
        }
        return solve(arr,n,dp);
        
        
    }
};