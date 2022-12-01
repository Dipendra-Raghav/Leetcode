class Solution {
public:
    // static bool comp(const vector<int>& a, const vector<int>& b){
    //     if(a[0]==b[0]){
    //         return a[1]>b[1];
    //     }
    //     return a[0]<b[0];
    // }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int p=0;
        int q=0;
        bool flag;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=intervals[q][1])
            {
                q=intervals[i][1]>intervals[q][1] ? i: q;
                flag=true;
                continue;
            }
            else
            {
                vector<int> res(2);
                res[0]=intervals[p][0];
                res[1]=intervals[q][1];
                ans.push_back(res);
                p=i;
                q=i;
                flag=false;
            }

        }
        
                vector<int> res(2);
                res[0]=intervals[p][0];
                res[1]=intervals[q][1];
                ans.push_back(res);
        
     
       
        return ans;
        
    }
};