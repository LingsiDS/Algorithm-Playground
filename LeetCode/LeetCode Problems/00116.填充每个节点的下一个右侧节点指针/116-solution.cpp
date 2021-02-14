//解法同117
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        Node* start = root;
        while (start) {
            Node *t = start, *next_start = nullptr;//next_start:下一层第一个节点
            Node* left = nullptr, *right = nullptr;
            for (; t; t = t->next) {//遍历该层节点,将下一层节点连接起来
                if (t->left) {
                    if (!left) left = t->left;
                    else if (!right) right = t->left; 
                    if (!next_start) next_start = t->left;
                }
                if (left && right) {//找到左右节点
                    left->next = right;
                    left = right;
                    right = NULL;
                }
                if (t->right) {
                    if (!left) left = t->right;
                    else if (!right) right = t->right;
                    if (!next_start) next_start = t->right;
                }
                if (left && right) {//找到左右节点
                    left->next = right;
                    left = right;
                    right = NULL;
                }
            }
            start = next_start;
        }
        return root;
    }
};

//递归版本，前序遍历，在遍历当前节点时构建链接关系，递归到下一层时可以使用到
//时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:

    void dfs(Node *root) {
        if (root == nullptr) return;

        if (root->left) {
            root->left->next = root->right;//完全二叉树保证，左子树存在，右子树存在或者为null
        }
        if (root->right) {
            if (root->next) {
                root->right->next = root->next->left;//root->next->left存在或者为null
            }
        }
        dfs(root->left);
        dfs(root->right);
    }

    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
};