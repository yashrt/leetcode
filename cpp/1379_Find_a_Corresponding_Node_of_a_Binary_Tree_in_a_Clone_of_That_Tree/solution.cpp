/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original)
        {
            if (original == target)
            return cloned;
            
            TreeNode* L = getTargetCopy(original->left, cloned->left, target);            
            if (L)
                return L;
            
            TreeNode* R = getTargetCopy(original->right, cloned->right, target);
            if (R)
                return R;
        }
        return NULL;
    }
};
