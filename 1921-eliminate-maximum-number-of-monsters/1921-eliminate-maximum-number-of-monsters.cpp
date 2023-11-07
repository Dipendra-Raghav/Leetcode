class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<float,vector<float>, greater<float>> pq;
        for(int i=0;i<dist.size();i++)
        {
            float num = static_cast<float>(dist[i]) / speed[i];
            pq.push(num);
        }
        int ans=0;
        int s=0;
        while(!pq.empty())
        {
            float tm=pq.top();
            pq.pop();
            cout<<tm<<" ";
            if(tm>s)ans++;
            else
                break;
            s++;
            
        }
        return ans;
        
        
    }
};