class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        unordered_map<string,char>mp;
        vector<string> str;
        string st="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                str.push_back(st);
                st="";
            }
            else
            {
                st=st+s[i];
            }
        }
        
        str.push_back(st);
        if(pattern.size()!=str.size())return false;
        for(int i=0;i<pattern.size();i++)
        {
            auto it=m.find(pattern[i]);
            auto itr=mp.find(str[i]);
            if(it==m.end())
            {
                if(itr==mp.end())
                {
                    m[pattern[i]]=str[i];
                    mp[str[i]]=pattern[i];
                }
                else
                {
                    return false;
                }
                
            }
            else
            {
                if(it->second==str[i])continue;
                else
                    return false;
            }
        }
        return true;
    }
};