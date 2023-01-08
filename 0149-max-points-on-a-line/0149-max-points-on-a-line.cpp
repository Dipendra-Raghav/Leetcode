class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        int mx=0;
        for(int i=0;i<n;i++)
        {
            int chk=0;
            unordered_map<float,int> mp;
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                float m;
                if((points[i][0]-points[j][0])==0)
                    m=100000;
                else
                {
                    m=float((points[i][1]-points[j][1]))/float((points[i][0]-points[j][0]));
                }
             
                auto it=mp.find(m);
                if(it!=mp.end())
                {
                    mp[m]++;
                    mx=max(mx,mp[m]);
                
                }
                else
                {
                    mp[m]++;
                    mx=max(mx,1);
                    
                }

            } 
           
            
        }
        return mx+1;
    }
};