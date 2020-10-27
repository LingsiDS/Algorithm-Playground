//双指针，pre表示当前遍历到的节点，cur尝试跳过pre之后相同的节点，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        auto pre = new ListNode;
        pre->next = head;
        ListNode *res = pre, *cur;
        while (pre) {
            cur = pre->next;//当前节点
            while (cur && cur->next && cur->val == cur->next->val) cur = cur->next;//cur跳过所有相同的节点
            if (cur == pre->next) pre = pre->next;//cur没有跳过任何节点，pre后移即可
            else pre->next = cur->next;           //pre指向下一个不同的节点
        }
        return res->next;
    }
};