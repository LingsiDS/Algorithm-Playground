//迭代法求解, 时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *pre = new ListNode, *first, *second, *res;
        res = head->next;
        pre->next = head;
        first = pre, second = head;
        while (second) {
            first = first->next;
            second = second->next;
            if (!second) return res;
            first->next = second->next;
            second->next = first;
            pre->next = second;
            pre = first;
            second = first->next;
        }
        return res;
    }
};

//递归求解，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return dfs(head);
    }

    ListNode* dfs(ListNode* head) {//递归思路，dfs反转head以及head->next两个节点，并返回反转后的首节点的指针
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* ret = dfs(head->next->next);//先递归反转后序节点
        ListNode *first = head, *second = head->next;
        second->next = first;//反转当前两个节点
        first->next = ret;
        return second;//返回反转后的头结点
    }
};