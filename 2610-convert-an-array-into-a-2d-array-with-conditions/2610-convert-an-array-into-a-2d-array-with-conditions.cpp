#include <vector>

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            bool flagg = true;

            for (int j = 0; j < ans.size(); ++j) {
                bool flag = true;

                for (int k = 0; k < ans[j].size(); ++k) {
                    if (x == ans[j][k]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    ans[j].push_back(x);
                    flagg = false;
                    break;
                }
            }

            if (flagg) {
                ans.push_back(vector<int>{x});  
            }
        }

        return ans;
    }
};
