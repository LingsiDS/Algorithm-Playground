/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* res = head;
        int c = 0;
        while (l1 && l2) {
            head->next = new ListNode;
            head = head->next;
            head->val = (l1->val + l2->val + c) % 10;
            c = (l1->val + l2->val + c) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            head->next = new ListNode;
            head = head->next;
            head->val = (l1->val + c) % 10;
            c = (l1->val + c) / 10;
            l1 = l1->next;
        }
        while (l2) {
            head->next = new ListNode;
            head = head->next;
            head->val = (l2->val + c) % 10;
            c = (l2->val + c) / 10;
            l2 = l2->next;
        }
        if (c) {
            head->next = new ListNode;
            head = head->next;
            head->val = c;
            c = 0;
        }
        head->next = nullptr;
        return res->next;
    }
};