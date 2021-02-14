//递归，每一个从根到叶子节点都是一个数字，可以使用先序遍历，将父节点的值乘以10加上当前节点的值
//即为当前数字的和，遍历到叶子节点时，就得到一个完整的数字，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode *root, int val) {
        if (root == nullptr) return;
        val = val * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += val;
            return;
        }
        dfs(root->left, val);
        dfs(root->right, val);
    }
};