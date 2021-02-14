//递归：自底向上枚举每个节点的高度，判断当前节点是否不满足
class Solution {
public:
    bool res = 1;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return res;
    }
 
    int dfs(TreeNode *root) {
        if (root == nullptr || !res) return 0;//!res表示已经判断出是非平衡的，直接返回
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (abs(l - r) > 1) {
            res = 0;
        }
        return max(l, r) + 1;
    }
};