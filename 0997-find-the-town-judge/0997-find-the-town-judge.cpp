class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // vector<int> ans(10001,0);
        // for(int i=0;i<trust.size();i++)
        // {
        //     ans[trust[i][0]]++;   
        // }
        // for(int i=0;i<trust.size();i++)
        // {
        //     if(ans[i]==0) return i;
        // }
        // return -1;
        // // map<int, int> mp;
        // // for(int i=0;i<n;i++)
        // // {
        // //     mp[trust[i][0]]++;
        // // }
        // // for(int i=0;i<=10000;i++)
        // // {
        // //     auto it=mp[i];
        // //     if()
        // // }
        
        vector<int> ans(n+1,0);
        vector<int> ans1(n+1,0);
        for(int i=0;i<trust.size();i++)
        {
            ans[trust[i][0]]++;
            ans1[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(ans[i]==0 && ans1[i]==n-1)return i;
        }
        return -1;
        
    }
};