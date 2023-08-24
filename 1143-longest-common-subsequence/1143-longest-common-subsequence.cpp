class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int chk=0;
        int chkk=0;
        
        for(int i=0;i<m;i++)
        {
            if(chk==1)dp[0][i]=1;
            else if(text1[0]==text2[i])
            {
                chk=1;
                dp[0][i]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(chkk==1)dp[i][0]=1;
            else if(text1[i]==text2[0])
            {
                chkk=1;
                dp[i][0]=1;
            }
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(text1[i]==text2[j])
                {
                    
                    dp[i][j]=1+dp[i-1][j-1];
                    //cout<<i<<","<<j<<"->"<<dp[i][j]<<"  ";
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    //cout<<i<<","<<j<<"->"<<dp[i][j]<<"  ";
                }
            }
            //cout<<endl;
        }
        return dp[n-1][m-1];
        
    }
};