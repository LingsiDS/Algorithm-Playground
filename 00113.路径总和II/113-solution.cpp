/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        dfs(root, sum, 0, path);
        return res;
    }

    void dfs(TreeNode* root, int sum, int s, vector<int>& path) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            s += root->val;
            path.push_back(root->val);
            if (s == sum) res.push_back(path);
            path.pop_back();//删除叶节点
            return;
        }
        s += root->val;
        path.push_back(root->val);
        dfs(root->left, sum, s, path);
        dfs(root->right, sum, s, path);
        path.pop_back();//左右子树遍历完，删除根节点
    }
};