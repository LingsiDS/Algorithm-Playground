//暴力枚举+哈希，时间复杂度O(n^2)，空间复杂度O(n)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hash;
        ListNode *t = headA;
        while (t) {
            hash.insert(t);
            t = t->next;
        }
        while (headB) {
            if (hash.count(headB)) {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};