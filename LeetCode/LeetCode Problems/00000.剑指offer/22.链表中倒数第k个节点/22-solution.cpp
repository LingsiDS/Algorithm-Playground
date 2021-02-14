//核心：双指针，起始快慢指针同时指向第一个节点，然后先让快指针走k步，之后两个指针一起移动即可。
//时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *res = head, *pre = head;
        while (k--) pre = pre->next;
        while (pre) {
            res = res->next;
            pre = pre->next;
        }
        return res;
    }
};