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
    void solve(TreeNode* root,vector<int> &num,int n,int i)
    {
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL)
        {
            n=n*10+root->val;
            cout<<n<<" ";
            num.push_back(n);
            return;
        }
        
        n=n*10+root->val;
        cout<<n<<" ";
        solve(root->left,num,n,i+1);
        solve(root->right,num,n,i+1);
        return;
        
    }
    int sumNumbers(TreeNode* root) {
        vector<int> num;
        solve(root,num,0,0);
        int ans=0;
        for(int i=0;i<num.size();i++)
        {
            ans+=num[i];
           
        }
        return ans;
        
    }
};