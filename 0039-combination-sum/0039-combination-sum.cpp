class Solution {
public:
    vector<vector<int>> ans;
     void solve(vector<int>& nums, int target,int j,vector<int> &res)
    {
        int sum=0;
        for(int i=0;i<res.size();i++)
        {
            
            sum+=res[i];
           
            
        }
        if(sum==target)
        {
            
            ans.push_back(res);
            return;
        }
        if(sum>target)return;
        
        for(int i=j;i<nums.size();i++)
        {
            res.push_back(nums[i]);
            solve(nums,target,i,res);
            res.pop_back();
            
          
        }
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       
        vector<int> res;
        solve(candidates,target,0,res);
        return ans;
        
        
    }
};