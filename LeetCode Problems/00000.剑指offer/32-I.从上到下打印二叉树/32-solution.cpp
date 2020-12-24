//bfs层序遍历树，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while (q.size()) {
            auto t = q.front(); q.pop();
            res.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        return res;
    }
};