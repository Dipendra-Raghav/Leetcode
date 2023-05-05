class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0;i<nums.size();i++)
            pq.push(nums[i]);
        
        int flag=true;
        int x=INT_MIN;
        int cnt=0;
        int mx=0;
        while(!pq.empty())
        {
            if(flag)
            {
               
                x=pq.top();
                pq.pop();
                cnt++;
                flag=false;
                cout<<cnt<<" ";
            }
            else if(pq.top()==x)
            {
                pq.pop();
            }
            else if(pq.top()==x+1)
            {
                cnt++;
                x=pq.top();
                pq.pop();
                
                cout<<cnt<<" ";
            }
            else
            {
                cnt=1;
                x=pq.top();
                pq.pop(); 
                cout<<cnt<<" ";
            }
            mx=max(mx,cnt);
                
        }
        if(nums.size()==0)return 0;
        return mx;
        
    }
};