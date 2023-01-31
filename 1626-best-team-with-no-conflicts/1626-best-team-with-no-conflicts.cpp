class Solution {
public:
    int n=0;
    int solve(vector<vector<int>> &arr,int curr,int prev,vector<vector<int>> &dp)
    {
        if(curr >=n)
        {
            return 0;
        }
        if(dp[curr][prev+1]!=-1)
        {
            return dp[curr][prev+1];
        }
        
        int take=0;
        int ntake=0;
    
        //take
        if(prev==-1 || arr[curr][1] >= arr[prev][1])
        {
            
            take = arr[curr][1]+solve(arr,curr+1,curr,dp);
        }
        
        //ntake
        ntake=solve(arr,curr+1,prev,dp); 
        return dp[curr][prev+1]=max(ntake,take);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        n=ages.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        vector<vector<int>> arr(n,vector<int> (2,0));
        for(int i=0;i<ages.size();i++)
        {
            arr[i][0]=ages[i];
            arr[i][1]=scores[i];
        }
        sort(arr.begin(),arr.end());
        return solve(arr,0,-1,dp);
        
    }
};