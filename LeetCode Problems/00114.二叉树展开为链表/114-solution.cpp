//关键点，将左子树（以左子树的根与左子树最右边的节点定位）插入到右子树中
//时间复杂度O(n)，每个节点最多被访问2次，空间复杂度O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left) {
                auto p = root->left;
                while (p->right) p = p->right;
                p->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }//以上保证root的左子树为空
            root = root->right;
        }
    }
};