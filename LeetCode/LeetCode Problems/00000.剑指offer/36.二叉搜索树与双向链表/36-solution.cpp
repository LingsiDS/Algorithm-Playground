//后续遍历二叉树，遍历过程中，返回当前子树中最右端节点和最左端节点，并将根节点转化为双向链表，递归左右子树
class Solution {
public:
    Node* first = NULL, *last = NULL;
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return NULL;
        auto p = dfs(root);
        p.first->left = p.second;//组成循环链表
        p.second->right = p.first;
        return p.first;
    }


    pair<Node*, Node*> dfs(Node* root) {
        if (!root->left && !root->right) {//叶节点
            return {root, root};
        }
        if (root->left && root->right) {//包含左右子树
            auto lside = dfs(root->left), rside = dfs(root->right);//后序遍历，返回以当前子树的最左端和最右端节点组成的pair
            lside.second->right = root, root->left = lside.second;//将根节点转化为双向链表
            root->right = rside.first, rside.first->left = root;
            return {lside.first, rside.second};
        }
        if (root->left) {//右子树为空
            auto lside = dfs(root->left);
            lside.second->right = root, root->left = lside.second;
            return {lside.first, root};
        }
        if (root->right) {//左子树为空
            auto rside = dfs(root->right);
            root->right = rside.first, rside.first->left = root;
            return {root, rside.second};
        }
        return {NULL, NULL};
    }
};

//先中序遍历二叉搜索树，得到递增的序列，并且将该序列存到哈希表中，，
class Solution {
public:
    Node *first = nullptr, *last = nullptr;
    unordered_map<int, Node*> hs;
    int idx = 0;
    Node* treeToDoublyList(Node* root) {
        inorder(root);
        for (int i = 0; i < idx; i++) {
            auto node = hs[i];
            node->left = hs[(i - 1 + idx) % idx];
            node->right = hs[(i + 1) % idx];
        }
        return hs[0];
    }

    void inorder(Node *root) {
        if (!root) return ;
        inorder(root->left);
        hs[idx++] = root;
        inorder(root->right);
    }
};