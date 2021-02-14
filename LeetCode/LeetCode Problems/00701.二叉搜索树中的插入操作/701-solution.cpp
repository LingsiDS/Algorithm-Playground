	/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//迭代,时间复杂度O(h)，空间复杂度O(1)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* pre = nullptr, *res = root;
        if (root == nullptr) return new TreeNode(val);
        while (root) {//找到val在树种的位置
            pre = root;
            if (root->val > val) root = root->left;
            else if (root->val < val) root = root->right;
        }
        auto t = new TreeNode(val);//创建节点，并将节点插入树种
        if (val < pre->val) pre->left = t;
        if (val > pre->val) pre->right = t;
        return res;
    }
};

//递归，时间复杂度O(h)，空间复杂度O(h)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        else if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};