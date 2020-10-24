//反转链表，迭代方法，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p1 = head, *p2 = head->next;

        while (p2) {
            ListNode *t = p2->next;
            p2->next = p1;//反转
            p1 = p2;//往后迭代
            p2 = t;
        } 
        head->next = NULL;
        return p1;
    }
};


//反转链表，递归解决，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* res = dfs(head, head->next);
        head->next = nullptr;
        return res;
    }

    //递归反转两个节点的连接
    ListNode* dfs(ListNode *pre, ListNode *cur) {
        ListNode *t = cur->next;
        cur->next = pre;//反转，这个版本先反转，再递归，从前往后反转
        if (t == nullptr) return cur;//到达结尾，return
        return dfs(cur, t);
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        ListNode* t = helper(head, NULL);
        head->next = NULL;
        return t;
    }
    ListNode* helper(ListNode* cur, ListNode* pre) {
        if (cur->next == NULL) {
            cur->next = pre;
            return cur;
        }
        ListNode* head =  helper(cur->next, cur);//这个递归版本是先递归，后反转，是从后往前反转
        cur->next = pre;
        return head;
    }
};
