//时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return root;
        swap(root->left, root->right);//交换两个儿子节点
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};