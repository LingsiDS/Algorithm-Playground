//双指针，cur从前往后遍历，pre指向要插入的节点，如果cur发现不满足的节点，将该节点插入到pre指向的节点之前
//时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode *pre = new ListNode;
        pre->next = head;
        ListNode *res = pre, *cur = pre;
        bool f = 0;
        while (cur) {
            if (cur->next && cur->next->val >= x && !f) {//置标记为1表示，发现第一个大于等于x的点，那么该点之后所有元素必须大于等于x
                f = 1;
            }
            if (cur->next && cur->next->val < x && f) {//在标记点后，发现比x小的节点
                auto p = cur->next;//将该节点插入到pre之后
                cur->next = p->next;
                p->next = pre->next;
                pre->next = p;
                pre = pre->next;//更新pre，使得pre一直指向第一个大于等于x的点
            }
            else cur = cur->next;//注意这里要加else，因为我们检测的是cur->next，删除一个节点后，如果又移到cur，那么可能会漏掉待检测的节点
            if (!f) pre = pre->next;//如果已经找到第一个大于等于x的点，则pre不变，一直指向该节点
        }
        return res->next;
    }
};

//更简便的做法，以链表的val为判断依据，将原链表分为两部分，第一部分所有节点的val小于x，第二部分所有节点的val大于x，最后将两个链表合并起来
//时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto small = new ListNode(-1);
        auto smallHead = small;
        auto large = new ListNode(-1);
        auto largeHead = large;
        while (head) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        small->next = largeHead->next;
        large->next = NULL;
        return smallHead->next;
    }
};