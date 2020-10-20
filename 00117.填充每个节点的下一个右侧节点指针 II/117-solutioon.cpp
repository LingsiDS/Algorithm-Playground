//使用BFS从右至左遍历树，依次处理每一层，将每一层处理成一个链表的形式
//时间复杂度：需要遍历所有的点O(n)，空间复杂度：使用队列O(n)
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;

        queue<Node*> q;
        q.push(root);
        int sz = 1, cnt = 0;
        Node* right_node = NULL;
        while (sz--) {
            auto t = q.front(); q.pop();
            t->next = right_node;
            right_node = t;
           
            if (t->right) {
                q.push(t->right);
                cnt++;
            }
            if (t->left) {
                q.push(t->left);
                cnt++;   
            }
            if (sz == 0) {//下一层
                sz = cnt;
                cnt = 0;
                right_node = NULL;
            }
        }
        return root;
    }
};



//优化第一种方法，时间复杂度不变，空间复杂度为O(1)
//当我们已经为某一层的next指针都赋值正确后,该层所有节点构成链表,我们不需要使用队列存储
//这个链表,直接遍历该链表,同时为下一层节点的next指针赋值,遍历完该层节点后,下一层节点
//又构成一个新的链表,进入下一层重复以上步骤
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


//第二种写法简化一点的版本
class Solution {
public:
    Node* connect(Node* root) {
        Node *head = root, *pre = nullptr, *cur = nullptr, *nextHead;
        while (head) {
            nextHead = nullptr;
            pre = nullptr;
            while (head) {
                if (head->left) {
                    if (!nextHead) nextHead = head->left;
                    if (pre) {
                        pre->next = head->left;
                        pre = pre->next;
                    }
                    else pre = head->left;
                }
                if (head->right) {
                    if (!nextHead) nextHead = head->right;
                    if (pre) {
                        pre->next = head->right;
                        pre = pre->next;
                    }
                    else pre = head->right;
                }
                head = head->next;
            }
            head = nextHead;;
        }
        return root;
    }
};