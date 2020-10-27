//链表排序过，只需要遍历一遍链表，跳过相同元素即可，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *res = head;
        while (head) {
            auto t = head;
            while (t->next && t->val == t->next->val) t =  t->next;
            if (head != t) head->next = t->next;
            else head = head->next;
        }
        return res;
    }
};