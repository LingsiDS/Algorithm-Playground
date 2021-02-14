//类似二分的思想，在树的最后一层二分分界点
//一个节点只有两种情况，要么是满二叉树，要么是完全二叉树，并且最多只有一个儿子是完全二叉树
//对于满二叉树，直接计算，对于完全二叉树，则递归计算
//时间复杂度O(logn*logn)，n为二叉树节点数目，因为树高为longn，每次递归要longn
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        auto l = root->left, r = root->right;
        auto x = 1, y = 1;
        while (l) l = l->left, x++;
        while (r) r = r->right, y++;
        if (x == y) return (1 << x) - 1;
        else return countNodes(root->left) + 1 + countNodes(root->right);
    }
};



//暴力算法O(n)
class Solution {
public:
    int countNodes(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode *root) {
        if (root == NULL) return 0;
        else return dfs(root->left) + dfs(root->right) + 1;
    }
};