class Solution {
public:
    int solve(vector<int>& days,vector<int>& costs,int i,vector<int> &dp)
    {
        if(i>=days.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        //for 1days
        int a= costs[0]+solve(days,costs,i+1,dp);
        
        // for 7 days
        int j;
        for(j=i;j<days.size() && days[j]<days[i]+7;j++);
        int b= costs[1]+solve(days,costs,j,dp);
        
        //for 30 days
        for(j=i;j<days.size() && days[j]<days[i]+30;j++);
        int c= costs[2]+solve(days,costs,j,dp);
        
        dp[i]= min(a,min(b,c));
        return dp[i];
    
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        return solve(days,costs,0,dp);
    }
};