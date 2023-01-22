class Solution {
public:
    vector<vector<string>> ans;
    bool chk(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    void solve(string &s, int k, vector<string> &curr)
    {
        if(k==s.size())
        {
            ans.push_back(curr);
            return;
        }
        for(int i=k;i<s.size();i++)
        {
           if(chk(s,k,i))
           {
               curr.push_back(s.substr(k,i-k+1));
               solve(s,i+1,curr);
               curr.pop_back();

           }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        solve(s,0,curr);
        return ans;
    }
};