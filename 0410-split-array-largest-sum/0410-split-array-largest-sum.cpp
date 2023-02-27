class Solution {
public:
    int isChk(vector<int>& nums, int k,int mid)
    {
        int sum=0;
        int cnt=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(nums[i] > mid) {
                return false;
            }
            if(sum>mid)
            {
                cnt++;
                sum=nums[i];
            }
            if(cnt > k) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int s=*max_element(nums.begin(),nums.end());
        int e=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(s==e)return mid;
            if(isChk(nums,k,mid))
            {
                ans=mid;
                e=mid;
                
            }
            else
                s=mid+1;
        }
        return ans;
        
    }
};