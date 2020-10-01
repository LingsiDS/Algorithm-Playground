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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode*> stk;
        while (!stk.empty() || root) {
            while (root) {
                stk.push(root);             //入栈
                res.push_back(root->val);   //访问
                root = root->left;
            }//while结束时，已经访问完根节点和左子树
            auto t = stk.top();             //弹出栈顶元素
            stk.pop();
            if (t->right) {                 //访问右子树
                root = t->right;
            }
        }
        return res;
    }
};