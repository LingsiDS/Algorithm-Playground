//递归解法，时间复杂度O(n), 空间O(n)
class Solution {
public:
    bool f1 = false, f2 = false;
    TreeNode* res = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }

    //返回一个整数，整数的第0位如果为1表示找到了q，第1为如果为1表示找到了p
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;
        auto l = dfs(root->left, p, q);
        auto r = dfs(root->right, p, q);
        int ret = l | r;
        if (root == p) ret = ret | 2;
        if (root == q) ret = ret | 1;     
        if ((ret == 3) && !res) res = root;//第一次找到了公共祖先
        return ret; 
    }
};

//也可以两次遍历，找最后一个不同的路径