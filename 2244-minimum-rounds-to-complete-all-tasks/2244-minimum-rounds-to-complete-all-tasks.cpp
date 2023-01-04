class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for(int i=0;i<tasks.size();i++)
        {
            m[tasks[i]]++;
        }
        int cnt=0;

        for(auto it: m)
        {
            if(it.second==1)return -1;
            if(it.second%3==0)cnt+=it.second/3;
            else
                cnt+=it.second/3+1;
        }
        return cnt;
        
    }
};