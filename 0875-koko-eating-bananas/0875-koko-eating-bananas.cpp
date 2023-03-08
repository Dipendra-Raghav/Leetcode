class Solution {
public:
    int isChk(vector<int> &piles,int mid, int h)
    {
        bool ans=false;
        int cnt=0;
        double x = mid;
        for(int i=0;i<piles.size();i++)
        {
            double t=piles[i]/x;
            cnt+=ceil(t);
          
        }
       
        if(cnt<=h)
        return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=*max_element(piles.begin(),piles.end());
        int s=1;
        int e=mx;
        cout<<e<<endl;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(s==e)break;
        
            bool ans=isChk(piles,mid,h);
            if(ans)
            {
                e=mid;
            }
            else 
                s=mid+1;
        }
        return s;
        
    }
};