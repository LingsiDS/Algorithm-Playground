//时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode* r1, TreeNode *r2) {//判断两棵树r1和r2是不是相等
        if (!r1 && !r2) return true;
        if (!r1 || !r2) return false;
        if (r1->val != r2->val) return false;
        return dfs(r1->left, r2->right) && dfs(r1->right, r2->left);
    }
};