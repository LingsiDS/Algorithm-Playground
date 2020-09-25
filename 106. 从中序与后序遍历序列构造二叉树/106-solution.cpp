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
    unordered_map<int, int> hash;//哈希表存储中序遍历序列，key为节点值，val为key在inorder数组的下标。方便快速查找根节点
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //由后序遍历的特性得出，后序遍历序列的最后元素即为当前根节点，idx始终指向根节点
        int idx = postorder.size()-1;
        for (int i = 0; i < inorder.size(); i++) hash[inorder[i]] = i;//构建哈希表
        return build(inorder, postorder, 0, inorder.size()-1, idx);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l, int r, int& idx) {
        if (l > r) return NULL;
        if (l == r) {//区间内只有一个元素时，创建该元素，并返回该元素
            idx--;//创建了一个元素后，根节点发生变化
            return new TreeNode(inorder[l]);
        }
        int root = postorder[idx--];//根节点为后序遍历序列的最后一个元素
        int x = hash[root];//得到根节点在中序遍历序列中的位置
        TreeNode* res = new TreeNode(root);//依据根节点创建节点
        res->right = build(inorder, postorder, x + 1, r, idx);//后序序列为:左右根，因先递归创建右子树
        res->left = build(inorder, postorder, l, x - 1, idx);//递归创建左子树
        return res;
    }
};