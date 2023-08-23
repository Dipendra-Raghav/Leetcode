class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=1;
        int pos=1;
        int ans=INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            if(pre==0)pre=1;
            if(pos==0)pos=1;
            pre=pre*nums[i];
            pos=pos*nums[nums.size()-i-1];
            ans=max(ans,max(pre,pos));
        }
        return ans;
        
    }
};