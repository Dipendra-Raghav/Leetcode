class Solution {
public:
    int n;
    int getIndex(vector<vector<int>> &job,int l,int k)
    {
        int r=n-1;
        int res=n+1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(job[mid][0]>=k)
            {
                res=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        
        }
        return res;
        
        
    }
    int solve(vector<vector<int>> &job,int i,vector<int> &dp)
    {
        if(i>=n)
            return 0;
        if(dp[i]!=-1)return dp[i];
        
        int ind=getIndex(job,i+1,job[i][1]);
        
        int incl=job[i][2]+solve(job,ind,dp);
        int excl=solve(job,i+1,dp);
        return dp[i]=max(incl,excl);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<vector<int>> job(n,vector<int>(3,0));
        
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++)
        {
            job[i][0]=startTime[i];
            job[i][1]=endTime[i];
            job[i][2]=profit[i];
        }
        sort(job.begin(),job.end());
        return solve(job,0,dp);
        
    }
};