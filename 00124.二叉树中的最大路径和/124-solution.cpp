//时间复杂度：O(n)，空间O(H)，H为树的深度
//较好的题解：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/shou-hui-tu-jie-hen-you-ya-de-yi-dao-dfsti-by-hyj8/
class Solution {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

    //dfs求解以root为根，root左半段，或者右半段的最大路径
    int dfs(TreeNode *root) {
        if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        int ret = max(root->val, left + root->val);
        ret = max(ret, root->val + right);
        
        //res求以root为根，不仅考虑左右半段的最大路径，还考虑两段合起来的最大路径（枚举所有组合成最大路径的状况）
        res = max(res, ret);
        res = max(res, left + right + root->val);
        return ret;
    }
};