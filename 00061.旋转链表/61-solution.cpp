//最多会扫描链表2次，时间复杂度为O(n^2)，空间复杂度为O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode* t = head, *last = nullptr;
        int cnt = 0;//存储链表节点的个数
        while (t) {
            cnt++;
            if (t->next == nullptr) last = t;
            t = t->next;
        }

        k = k % cnt;
        int steps = cnt - k;//最后的链表的头节点为head指针从头向右走steps步

        if (steps == 0) return head;//如果不需要走，直接返回
        last->next = head;//连成环

        ListNode* pre = new ListNode;
        pre->next = head;
        while (steps--) {//走steps步
            pre = pre->next;
            head = head->next;
        }
        pre->next = nullptr;//将原本指向head节点的指针指向nullptr（该节点为新链表的尾节点）
        return head;
    }
};