class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())return false;
        map<char,int> mp;
        for(int i=0;i<word1.size();i++)
        {
            mp[word1[i]]++;
        }
        map<char,int> mt;
        for(int i=0;i<word2.size();i++)
        {
            mt[word2[i]]++;
        }
        vector<int> w1;
        vector<int> w2;
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            w1.push_back(it->second);
        }
        for(auto it = mt.begin();it!=mt.end();it++)
        {
            w2.push_back(it->second);
        }
        for(int i=0;i<word1.size();i++)
        {
            if(mt.find(word1[i])==mt.end())return false;
        }
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        for(int i=0;i<w1.size();i++)
        {
            if(w1[i]!=w2[i])return false;
        }
        return true;
        
    }
};