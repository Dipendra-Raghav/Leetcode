class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> lheight(n);
        vector<int> rheight(n);
        // lheight[0]=0;
        // rheight[n-1]=0;
        for(int i=1;i<n;i++)
        {
            lheight[i]=max(lheight[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            rheight[i]=max(rheight[i+1],height[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int ht=min(lheight[i],rheight[i]);
            if(height[i]<=ht)
                ans+=ht-height[i];
           
        }
        return ans;
        
    }
};