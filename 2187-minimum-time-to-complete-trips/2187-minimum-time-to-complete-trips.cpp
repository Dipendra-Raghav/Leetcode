class Solution {
public:
    
    bool isValid(long long mid,vector<int> &time, int k)
    {
       long long cnt = 0;
        for(int i : time) {
            cnt += mid / i;
            if(cnt >= 1e18) return true;
        }
        return cnt >= k;
        
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long s=1;
        long long e = 1e18;
        long long ans=0;
        while(s<=e)
        {
            long long mid=(s+e)/2;       
            if(isValid(mid,time,totalTrips))
            {
                e=mid-1;
                ans=mid;
            }
            else
            {
                s=mid+1; 
            }
        }
       
        return ans;
        
    }
};