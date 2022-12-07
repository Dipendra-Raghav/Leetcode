class Solution {
public:
    // int n;
    // int getind(vector<vector<int>> intervals,int i,int k)
    // {
    //     int ans=n+1;
    //     int j=n-1;
    //     while(i<=j)
    //     {
    //         int mid=i+(j-i)/2;
    //         if(intervals[mid][0]>=k)
    //         {
    //             ans=mid;
    //             j=mid-1;
    //         }
    //         else
    //         {
    //             i=mid+1;
    //         }
    //     }
    //     return ans;
    // }
    // int solve(vector<vector<int>>& intervals,int i,vector<int> &dp)
    // {
    //     if(i>=n)return 0;
    //     if(dp[i]!=-1)return dp[i];
    //     //include
    //     int ind=getind(intervals,i+1,intervals[i][1]);
    //     int incl=1+solve(intervals,ind,dp);
    //     //exclude
    //     int excl=solve(intervals,i+1,dp);
    //     return dp[i]=max(incl,excl);
    // }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       int  n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int ans;
        int k=0;
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>=intervals[k][1])
            {
                k=i;
                continue;
            }
                
            else if (intervals[i][0]<intervals[k][1])
            {
                k=intervals[i][1]<=intervals[k][1]?i:k;
                cnt++;
                
            }
        }
        return cnt;
        
        
    }
};