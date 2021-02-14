////时间复杂度O(n)，空间复杂度O(n)
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

//时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }

    void dfs(TreeNode *root) {
        if (root == nullptr) return;
        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};


//Mirror遍历，没有左子树的节点被访问一次，有左子树的节点被访问两次，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        while (root) {
            if (root->left) {
                TreeNode *pre = root->left;
                while (pre->right && pre->right != root) pre = pre->right;
                if (pre->right == nullptr) {
                    res.push_back(root->val);
                    pre->right = root;
                    root = root->left;
                } else {
                    root = root->right;
                    pre->right = nullptr;
                }

            } else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};