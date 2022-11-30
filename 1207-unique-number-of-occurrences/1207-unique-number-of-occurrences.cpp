class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        set<int> s;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        int cnt=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            s.insert(it->second);
            cnt++;
        }
        
        if(s.size()==cnt)return true;
        else return false;
    }
};