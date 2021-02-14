//基于bst中序遍历的有序性，使用反中序遍历（右子树，根，左子树），统计遍历节点的次序n，第n==k时遍历到第k大元素
//时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int res = 0;
    int n = 0;
    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }

    void dfs(TreeNode *root, int k) {
        if (!root || res) return;
        dfs(root->right, k);
        n++;//逆中序遍历，统计第k大的数
        if (n == k) res = root->val;
        dfs(root->left, k);
    }
};