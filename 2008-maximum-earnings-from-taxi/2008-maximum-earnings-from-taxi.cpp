class Solution {
public:
    
    int getIndex(vector<vector<int>> &rides,int l,int target,int n)
    {
        int r=n-1;
        int res=n+1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(rides[mid][0]>=target)
            {
                res=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return res;
    }

    long long solve(vector<vector<int>> &rides,int i,int n,vector<long long> &dp)
    {
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int ind=getIndex(rides,i+1,rides[i][1],n);
        //take
        long long incl=((rides[i][1]-rides[i][0])+rides[i][2])+ solve(rides,ind,n,dp);
        //not take
        long long excl=solve(rides,i+1,n,dp);
        return dp[i]=max(incl,excl);
        
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        n=rides.size();
        sort(rides.begin(),rides.end());
        vector<long long> dp(n,-1);
        return solve(rides,0,n,dp);
        
    }
};