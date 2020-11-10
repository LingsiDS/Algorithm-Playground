//根据BST的性质，不断划分区间，如果当前根节点不再区间范围内，则返回false，注意区间范围要使用long long
//时间复杂度遍历一遍树O(n)，空间复杂度O(n)递归深度为树的高度，最坏情况下退化为链表
class Solution {
public:
    using LL = long long;
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }

    bool dfs(TreeNode *root, LL left, LL right) {
        if (root == nullptr) return true;
        if (root->val < left || root->val > right) return false;
        return dfs(root->left, left, (LL)root->val - 1) && dfs(root->right, (LL)root->val + 1, right);
    }
};

//根据BST的中序遍历是单调递增的性质，进行中序遍历，如果是单调递增的，说明是BST，否则不是
class Solution {
public:
    long long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
    bool dfs(TreeNode *root) {
        if (root == nullptr) return true;
        bool l = dfs(root->left);
        if (pre == LONG_MIN) {
            pre = root->val;
        }else {
            if (root->val <= pre) return false;
            pre = root->val;
        }
        bool r = dfs(root->right);
        return l && r;
    }
};