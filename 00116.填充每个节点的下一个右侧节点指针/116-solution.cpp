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