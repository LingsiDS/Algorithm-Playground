//使用两个栈层序遍历树，假设根节点为第1层，则奇数层从左到右打印，偶数层从右到左打印
//使用两个栈s1和s2分别存储从左到右和从右到左打印的序列，并且在遍历s1时生成s2，此时
//对于s1中节点的左右孩子应该按（left， right）顺序放入s2，而在遍历s2生成s1时，应该按
//(right, left)的顺序入栈。

//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        stack<TreeNode*> s1;//存储的从左向右输出的序列
        stack<TreeNode*> s2;//存储的从右向左输出的序列
        s1.push(root);
        int layer = 0;

        while (s1.size() || s2.size()) {
            layer++;//根节点为第一层
            vector<int> l;
            if (layer % 2 == 1) {//奇数层
                int cnt = s1.size();
                for (int i = 0; i < cnt; i++) {
                    auto t = s1.top(); s1.pop();
                    l.push_back(t->val);
                    if (t->left) s2.push(t->left);//左右
                    if (t->right) s2.push(t->right);
                }
            } else {//偶数
                int cnt = s2.size();
                for (int i = 0; i < cnt; i++) {
                    auto t = s2.top(); s2.pop();
                    l.push_back(t->val);
                    if (t->right) s1.push(t->right);//右左
                    if (t->left) s1.push(t->left);
                }
            }
            res.push_back(l);
        }
        return res;
    }
};