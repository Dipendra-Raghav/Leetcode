class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> graph(n+1,{0,0});
        for(int i = 0; i < trust.size(); i++){
            graph[trust[i][0]].first += 1;         
            graph[trust[i][1]].second += 1;        
        }
        
        for(int i = 1; i <= n; i++){
            if(graph[i].first == 0 && graph[i].second == n-1)   
                return i;
        }
        return -1;
    }
};