class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int k=points[0][1];
        int cnt=0;
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]<=k)
            {
                k=min(k,points[i][1]);
                continue;
            }
            else
            {
                cnt++;
                k=points[i][1];
            }
        }
        return cnt+1;
        
    }
};