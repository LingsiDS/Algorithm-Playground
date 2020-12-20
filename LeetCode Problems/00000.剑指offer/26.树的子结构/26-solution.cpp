//递归，本题注意时间复杂度分析，时间复杂度为O(m*n)，m为A的节点数，n为B的节点数
//复杂度分析的关键在于第17，18行，可以看到最坏情况下，17行先判断A的当前节点是否包含B，如果失败
//18行还要继续递归左右子树，最坏情况下A的每个节点判断n次发现不包含B的子结构，然后再进入左右子树
class Solution {
public:
    TreeNode *root;
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        root = B;
        if (!A || !B) return false;//特判，处理边界
        return dfs(A, B);
    }
    bool dfs(TreeNode* A, TreeNode* B) {
        if (A == NULL && B == NULL) return true;
        if (!A && B) return false;
        if (A && !B) return true;
        if (A->val == B->val)
            return dfs(A->left, B->left) && dfs(A->right, B->right) || //分别递归判断A的左右子树是否包含B的左右子树
                    dfs(A->left, root) || dfs(A->right, root);  //如果上面判断失败，重新开始检查B
        else return dfs(A->left, root) || dfs(A->right, root);//不相等，重新开始检查B
    }
};