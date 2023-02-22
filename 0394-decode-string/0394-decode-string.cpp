class Solution {
public:
    string solve(string &s, int &i)
    {
        string ans="";
        while(i<s.size())
        {
            if(s[i]==']') return ans;
            if(isdigit(s[i]))
            {
                int k  = 0;
                while(s[i]>='0' && s[i]<='9')
                {
                    k  = k*10 + s[i]-'0';
                    i++;
                }
                i++;
                string str=solve(s,i);
                while(k)
                {
                    ans+=str;
                    k--;
                }     
            }
            else
            {
                ans+=s[i];
            }
            i++;
            
        }
        return ans;
    }
    string decodeString(string s) {
        int i=0;
        return solve(s,i);
        
    }
};