class Solution {
public:
    int n;
    int getIndex(vector<vector<int>> &events,int l,int target)
    {
        int r=n-1;
        int res=n+1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(events[mid][0]>target)
            {
                res=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return res;
    }
    // int solve(vector<vector<int>> &events,int i,int k)
    // {
    //     //base condn
    //     if(i>=n || k==2)return 0; 
    //     int ind=getIndex(events,i+1,events[i][1]);
    //     //take
    //     int incl=events[i][2]+solve(events,ind,k+1);
    //     //not take
    //     int excl=solve(events,i+1,k);
    //     return max(incl,excl);
    // }
    int solvedp(vector<vector<int>> &events,int i,int k,vector<vector<int>> &dp)
    {
        //base condn
        if(i>=n || k==2)return 0; 
        if(dp[i][k]!=-1)return dp[i][k];
        int ind=getIndex(events,i+1,events[i][1]);
        //take
        int incl=events[i][2]+solvedp(events,ind,k+1,dp);
        //not take
        int excl=solvedp(events,i+1,k,dp);
        return dp[i][k]=max(incl,excl);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n=events.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        sort(events.begin(),events.end());
        return solvedp(events,0,0,dp);
      //  return solve(events,0,0);
        
    }
};