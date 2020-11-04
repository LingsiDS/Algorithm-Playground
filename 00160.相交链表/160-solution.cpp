//双指针，时间复杂度O(m + n)，空间复杂度O(1)
//设置两个指针分别指向两个链表的头结点，同时向后遍历，如果走到末尾则将该指针重新定位到另一个指针的起始位置
//这样两个指针走过的“路程”相等，如果有交点，则会在交点处相遇，否则会同时走到末尾空节点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *first = headA, *second = headB;
        while (first != second) {
            first = first == nullptr ? headB : first->next;
            second = second == nullptr ? headA : second->next;   
        }
        return first;
    }
};

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