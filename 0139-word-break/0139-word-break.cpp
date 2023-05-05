class Solution {
public:
    int ans=-2;

   bool solve(string &s,int i, unordered_map<string,int> &mp,vector<int> &dp )
    {
        if(i>=s.size() )return true;
     
       
       if(dp[i]!=-1)return dp[i];
       string str;
           for(int j=i;j<s.size();j++)
           {
                str+=s[j];
               if(mp.find(str)!=mp.end())
        {
            if(solve(s,j+1,mp,dp)) return dp[i]=true;
            
        }
           }
       return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& word) {
        unordered_map<string,int> mp;
        for(int i=0;i<word.size();i++)
        {
            mp[word[i]]++;
        }
        vector<int> dp(301,-1);
        string str="";
        return solve(s,0,mp,dp);

    }
};