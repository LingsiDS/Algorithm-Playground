//先序遍历树，记录遍历的路径，以及路径上的数之和，到达叶子节点时，如果和等于target则将当前路径加入到答案

//时间复杂度O(n)，空间复杂度O(n)
class Solution {
public: 
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        dfs(root, path, 0, sum);
        return res;
    }

    void dfs(TreeNode *root, vector<int> &path, int sum, int target) {
        if (!root) return ;
        sum += root->val;           //先序遍历
        path.push_back(root->val);
        if (!root->left && !root->right) {//到达叶子节点
            if (sum == target) {
                res.push_back(path);
            }
            path.pop_back();
            return;
        }
        dfs(root->left, path, sum, target);
        dfs(root->right, path, sum, target);
        path.pop_back();
    }
};