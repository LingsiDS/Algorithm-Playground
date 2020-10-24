//递归，复杂度为卡特兰数，递归思路有，但是不知道怎么存储，怎么创建，需要多练
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return {};
        return dfs(1, n);    
    }

    vector<TreeNode*> dfs(int l, int r) {
        if (l > r) return {nullptr};//递归出口
        vector<TreeNode*> res;

        for (int i = l; i <= r; i++) {
            //创建左子树，创建右子树
            auto left = dfs(l, i - 1), right = dfs(i + 1, r);
            for (auto l: left) {
                for (auto r: right) {
                    TreeNode * root = new TreeNode(i);//创建根节点
                    root->left = l;//拼接左右子树
                    root->right = r;
                    res.push_back(root);//添加到答案
                }
            }
        }
        return res;//返回
    }
};