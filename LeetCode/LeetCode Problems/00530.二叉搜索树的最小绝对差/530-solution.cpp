//中序遍历得到递增序列，检查相邻序列的最小差即可，时间复杂度O(n),空间复杂度O(n)
//第一次做额外使用数组得到中序遍历的结果，更好的做法是在递归过程中进行计算，对这方面掌握不好
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int pre = -1, ans = INT_MAX;
        inorder(root, pre, ans);
        return ans;
    }

    void inorder(TreeNode *root, int &pre, int &ans) {
        if (root == NULL) return;
        inorder(root->left, pre, ans);
        if (pre == -1) {
            pre = root->val;
        }
        else {
            ans = min(ans, abs(root->val - pre));
            pre = root->val;
        }
        inorder(root->right, pre, ans);
    }
};