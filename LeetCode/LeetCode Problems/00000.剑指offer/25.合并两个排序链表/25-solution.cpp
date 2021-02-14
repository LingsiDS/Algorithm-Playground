//时间复杂度O(n + m)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *head = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                head->next = l1;
                l1 = l1->next;
                head = head->next;
            } else {
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            }
        }
        if (l1) head->next = l1;
        if (l2) head->next = l2;
        return dummy->next;
    }
};