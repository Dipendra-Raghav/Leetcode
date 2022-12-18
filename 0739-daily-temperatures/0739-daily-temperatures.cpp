class Solution {
public:
    vector<int> solve(vector<int>& t)
    {
        vector<int> res(t.size(), 0);
        vector<int> stk;
        
        for(int i=0; i<t.size(); i++){
            while(stk.size() && t[stk.back()] < t[i]){
                res[stk.back()] = i - stk.back();
                stk.pop_back();
            }
            stk.push_back(i);
        }
        
        return res;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return solve(temperatures);
        
    }
};