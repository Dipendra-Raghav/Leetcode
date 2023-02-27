class Solution {
public:
    bool isChk(vector<int> &P, int mid, int M)
    {
        int prev = 0;
        int count = 1;
        for(int i=1;i<P.size();i++)
        {
            if(abs(P[prev]-P[i]) >= mid)
            {
                prev = i;
                count++;
            }
            if(count >= M)
                return true;
        }
        return count >= M;
    }
    int maxDistance(vector<int>& nums, int m) {
        sort(nums.begin(),nums.end());
        int s=1;
        int e=nums[nums.size()-1];
        int ans=0;
        while(s<e)
        {
            int mid=(s+e)/2;
            if(isChk(nums,mid,m))
            {
                ans=mid;
                s=mid+1;
            }
            else
                e=mid;
        }
        return ans;
        
    }
};