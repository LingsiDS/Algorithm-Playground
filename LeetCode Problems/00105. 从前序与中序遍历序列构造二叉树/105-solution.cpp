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
    unordered_map<int, int> hash;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < preorder.size(); i++) hash[inorder[i]] = i;
        int idx = 0;
        return build(preorder, inorder, 0, inorder.size()-1, idx);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r, int& idx) {
        if (l > r) return NULL;
        if (l == r) {
            idx++;
            return new TreeNode(inorder[l]);
        }
        int rootVal = preorder[idx++];
        TreeNode* root = new TreeNode(rootVal);
        int x = hash[rootVal];
        root->left = build(preorder, inorder, l, x - 1, idx);
        root->right = build(preorder, inorder, x + 1, r, idx);
        return root;
    }
};