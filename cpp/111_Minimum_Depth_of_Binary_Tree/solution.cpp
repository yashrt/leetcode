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
    int help(TreeNode* root, int ans)
    {
        if (root->left == NULL && root->right==NULL)
            return ans+1;
        else 
        {
            int l = INT_MAX, r = INT_MAX;
            if (root->left)
                l = help(root->left, ans+1);
            if (root->right)
                r = help(root->right, ans+1);    
            return min(l,r);
        }
    }
    
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        
        return help(root, 0);
    }
};
