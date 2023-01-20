class Solution {
public:
    int n;
    set<vector<int>> ans;
    void solve(vector<int> &nums,int i,vector<int> &res,int k)
    {
        if(i>=n)
        {
            
            if(res.size()>=2) 
            {
                ans.insert(res);
            } 
            return;
        }
        //exclude
        solve(nums,i+1,res,k);
        //include
        if(k==INT_MIN || nums[i]>=k)
        {
            res.push_back(nums[i]);
            solve(nums,i+1,res,nums[i]);
            res.pop_back();
        }
        
        return;
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        vector<int> res;
        solve(nums,0,res,INT_MIN);
        vector<vector<int>> anss(ans.begin(),ans.end());
        return anss;
        
    }
};