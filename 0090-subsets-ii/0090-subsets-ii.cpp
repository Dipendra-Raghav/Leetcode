class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& nums,vector<int> &ans,int i)
    {
        
            res.push_back(ans);
      
        
        for(int k=i;k<nums.size();k++)
        {
            if(k>i && (nums[k]==nums[k-1]))
            {
               
                continue;
            }
            //include
            ans.push_back(nums[k]);
            solve(nums,ans,k+1);
            ans.pop_back();
        }
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        solve(nums,ans,0);
        return res;
        
    }
};