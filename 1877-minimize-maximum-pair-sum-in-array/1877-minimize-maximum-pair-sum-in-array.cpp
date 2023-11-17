class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // priority_queue<int> q;
        // for(int i=0;i<nums.size();i++)
        //     q.push(nums[i]);
        
        sort(nums.begin(),nums.end());
        int j=nums.size()-1;
        int mn=INT_MIN;
        for(int i=0;i<nums.size()/2;i++)
        {
            int ans = nums[i]+nums[j];
            mn=max(mn,ans);
            j--;
        }
        return mn;
        
        
    }
};