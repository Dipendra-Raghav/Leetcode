class Solution {
public:
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        ll ans=0;
        while(!q.empty())
        {
            ll size=q.size();
            ll n=q.front().second;
            ll m=q.back().second;
            ans=max(ans,m-n+1);
            
            for(ll i=0;i<size;i++)
            {
                TreeNode* node=q.front().first;
                ll ind=q.front().second;
                
                q.pop();
                if(node->left!=NULL)
                    q.push({node->left,2*ind+1});
                if(node->right!=NULL)
                    q.push({node->right,2*ind+2});
            }
        }
        return ans;
        
        
    }
};