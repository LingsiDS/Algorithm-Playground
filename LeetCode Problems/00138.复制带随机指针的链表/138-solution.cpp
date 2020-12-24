//两次遍历，第一次遍历原链表，复制每个节点，使用哈希表存储原链表和新链表的映射关系
//第二次遍历原链表的所有边，在新链表中连接好所有边

//时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        mp[NULL] = NULL;
        Node * cur = head;
        while (cur) {
            auto t = new Node(cur->val);
            mp[cur] = t;
            cur = cur->next;
        }

        Node *res = new Node(-1);
        cur = res;
        while (head) {
            cur->next = mp[head];
            cur = cur->next;
            cur->random = mp[head->random];
            head = head->next;
        }
        return res->next;
    }
};


//方法二：时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //创建副本
        Node *cur = head;
        while (cur) {
            auto t = new Node(cur->val);
            t->next = cur->next;
            cur->next = t;
            cur = t->next;
        }

        //复制random指针
        cur = head;
        while (cur) {
            cur->next->random = (cur->random ? cur->random->next : NULL);
            cur = cur->next->next;
        }

        //拆分两个链表
        Node *res = new Node(-1), *last = res;
        cur = head;
        while (cur) {
            last->next = cur->next;
            last = last->next;
            cur->next = last->next;
            cur = cur->next;
        }
        last->next = NULL;
        return res->next;
    }
};