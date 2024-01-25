class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+2,vector<int> (m+2,0));
        // for(int i=0;i<n;i++)dp[i][0]=0;
        // for(int j=0;j<m;j++)dp[0][j]=0;
        for(int i=1;i<=n+1;i++)
        {
            for(int j=1;j<=m+1;j++)
            {
                int take=0,ntake=0;
                if(text1[i-1]==text2[j-1])
                {
                    take=1+dp[i-1][j-1];
                }
                ntake=max(dp[i-1][j],dp[i][j-1]);
                dp[i][j]=max(take,ntake);
            }
        }
        return dp[n+1][m+1]-1;
        
    }
};