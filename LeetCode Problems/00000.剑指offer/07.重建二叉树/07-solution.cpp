class Solution {
public:
    unordered_map<int, int> hash;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) hash[inorder[i]] = i;
        int idx = 0;
        return build(inorder, preorder, 0, inorder.size() - 1, idx);
    }

    //以inorder[l, r]的元素构建二叉树，其中根节点为preorder[idx]
    TreeNode* build(vector<int> &inorder, vector<int> &preorder, int l, int r, int &idx) {
        if (l > r) return nullptr;
        int root_val = preorder[idx++];
        int root_idx = hash[root_val];
        auto t = new TreeNode(root_val);
        t->left = build(inorder, preorder, l, root_idx - 1, idx);
        t->right = build(inorder, preorder, root_idx + 1, r, idx);
        return t;
    }
};