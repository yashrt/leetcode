/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    TreeNode* buildBST(stringstream& tree)
    {
        string s;
        tree >> s;
        
        if(s == "null")
            return NULL;
        
        TreeNode* node = new TreeNode(stoi(s));
        node->left = buildBST(tree);
        node->right = buildBST(tree);
        
        return node;
    }
     
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return !root ? " null" : " " + to_string(root->val) + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream tree(data);
        return buildBST(tree);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
