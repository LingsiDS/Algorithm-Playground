//bfs层序遍历+分层
//时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        int cnt = q.size();
        vector<vector<int>> res;
        vector<int> l;
        while (cnt--) {
            auto t = q.front(); q.pop();
            l.push_back(t->val);
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
            if (cnt == 0) {
                res.push_back(l);
                l.clear();
                cnt = q.size();   
            }
        }
        return res;
    }
};