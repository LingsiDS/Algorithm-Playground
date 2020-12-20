//时空复杂度O(h), h为树的高度
//利用二叉搜索树的性质，如果p/q的val一个小于root的val，另一个大于root->val则说明当前root就是LCA
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) {
            auto t = p;
            p = q;
            q = t;//保证p为较小的那个
        }
        return dfs(root, p, q);
    }

    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        if (p->val <= root->val && q->val >= root->val) return root;
        else if (p->val < root->val && q->val < root->val) return dfs(root->left, p, q);
        else return dfs(root->right, p, q);//(p->val > root->val && q->val > root->val)
        
    }
};