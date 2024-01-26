class Solution {
public:
    
    int rw;
    int cl;
    int solve(int mx, int sR, int sC,vector<vector<vector<int>>> &dp)
    {
        
        //base condn
        if((sR<0 || sR>=rw || sC<0 || sC>=cl))
        {
                return 1;
        }
        if(mx==0)return 0;
        
        if(dp[sR][sC][mx]!=-1)return dp[sR][sC][mx];
        int ans=0;
        // right
        ans = (ans + solve(mx - 1, sR, sC + 1, dp)) % 1000000007;
        // left
        ans = (ans + solve(mx - 1, sR, sC - 1, dp)) % 1000000007;
        // top
        ans = (ans + solve(mx - 1, sR - 1, sC, dp)) % 1000000007;
        // down
        ans = (ans + solve(mx - 1, sR + 1, sC, dp)) % 1000000007;
      
        return dp[sR][sC][mx]=ans;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        rw=m;
        cl=n;
     vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));

        return solve(maxMove,startRow,startColumn,dp);
        
        
    }
};