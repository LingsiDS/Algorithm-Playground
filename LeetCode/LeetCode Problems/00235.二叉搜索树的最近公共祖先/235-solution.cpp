/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//遍历两次，利用二叉搜索树的性质分别查找两个节点，同时从上往下记录查找的路径
//依次比较两条路径，最近公共祖先为最后一个相同的节点
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1, p2;
        find_node(root, p, p1);
        find_node(root, q, p2);
        TreeNode* res = NULL;
        for (int i = 0; i < p1.size() && i < p2.size(); i++) {
            if (p1[i] == p2[i]) res = p1[i];
        }
        return res;
    }

    void find_node(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == NULL) return;
        path.push_back(root);
        if (target->val < root->val) find_node(root->left, target, path);
        if (target->val > root->val) find_node(root->right, target, path);
        if (target->val == root->val) return;
    }
};


//一次遍历法，利用二叉搜索树的性质，当p1->val 和p2->val都小于root->val时，查找左子树
//当p1->val 和p2->val都大于root->val时，查找右子树，当一个大于root->val一个小于root->val时，
//此时root节点即为最近公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};