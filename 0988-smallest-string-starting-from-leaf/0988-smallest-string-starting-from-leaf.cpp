/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string ans="zzzzzzzzz";
    bool smaller(const string& str1, const string& str2) {
    for (int i = 0; i < str1.size() && i < str2.size(); i++) {
        if (str1[i] < str2[i])
        {
            return true;
        } else if (str1[i] > str2[i]) 
        {
            return false;
        }
    }
    return str1.size() < str2.size();
}

    void solve(TreeNode* root,string s)
    {
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL)
        {
            int n=root->val+97;
            char ch=tolower(n);
            s=ch+s;
            ans=smaller(s,ans)==true? s:ans;
            return;
        }
        int n=root->val+97;
        char ch=tolower(n);
        s=ch+s;
        solve(root->left,s);
        solve(root->right,s);
        return;
        
    }
    string smallestFromLeaf(TreeNode* root) {
        string s;
        cout<<root->val;
        solve(root,s);
        return ans;
        
    }
};