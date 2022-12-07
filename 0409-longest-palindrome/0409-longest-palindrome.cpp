class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        bool flag=false;
        int ans=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second%2==0)
                ans+=it->second;
            else
            {
                ans+=it->second-1;
                flag=true;
            }
        }
        ans=flag==true?ans+1:ans;
        return ans;
    }
};