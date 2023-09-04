class Solution {
public:
    int solve(string word1,string word2,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=word1.size() && j>=word2.size())
            return 0;
        
        if(i>=word1.size())
        {
            return word2.size()-j;
        }
        if(j>=word2.size())
        {
            return word1.size()-i;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        int a=INT_MAX;
        int b=INT_MAX;
        int c=INT_MAX;
        int d=INT_MAX;
        //go on
        if(word1[i]==word2[j])
        {
            a=solve(word1,word2,i+1,j+1,dp);
        }
        
        else
        {
            //replace
            b=1+solve(word1,word2,i+1,j+1,dp);
            //delete
            c=1+solve(word1,word2,i+1,j,dp);
            //insert
            d=1+solve(word1,word2,i,j+1,dp);
        }
        return dp[i][j]=min(a,min(b,min(c,d)));
        
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return solve(word1,word2,0,0,dp);
    }
};