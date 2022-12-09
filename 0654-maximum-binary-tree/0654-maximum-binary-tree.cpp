class Solution {
public:
    int getIndex(vector<int>& nums, unordered_map<int,int> &m, int l, int r)
    {
        int mx = *max_element(nums.begin() + l, nums.begin() + r + 1);
        auto it = m.find(mx);
        return it->second;
    }
    TreeNode* solve(vector<int>& nums, unordered_map<int,int> &m, int l, int r)
    {
        if (l < 0 || r < 0 || l >nums.size()-1 || r > nums.size()-1)
            return NULL;
        int ind = getIndex(nums, m, l, r);
        TreeNode* root = new TreeNode(nums[ind]);
        root->val = nums[ind];

        if(ind>l) root->left = solve(nums, m, l, ind-1);
        if(ind<r) root->right = solve(nums, m, ind+1, r);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;

        return solve(nums, m, 0, nums.size()-1);
    }
};
