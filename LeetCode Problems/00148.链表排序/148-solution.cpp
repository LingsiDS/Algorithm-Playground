//v1， 递归版，时间复杂度O(nlogn)，空间复杂度O(logn)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        return merge_sort(head);
    }

    //快慢指针获得中间节点
    ListNode *get_mid(ListNode *head) {
        ListNode *pre = head, *cur = head->next;
        while (cur) {
            cur = cur->next;
            if (!cur) break;
            cur = cur->next;
            pre = pre->next;
        }
        auto t = pre->next;
        pre->next = nullptr;
        return t;
    }

    //链表归并
    ListNode *merge(ListNode *h1, ListNode *h2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (h1 && h2) {
            if (h1->val <= h2->val) {
                cur->next = h1;
                h1 = h1->next;
                cur = cur->next;
            }
            else {
                cur->next = h2;
                h2 = h2->next;
                cur = cur->next;
            }
        }
        if (h1) cur->next = h1;
        if (h2) cur->next = h2;
        return dummy->next;
    }

    ListNode* merge_sort(ListNode *head) {
        if (head->next == nullptr) return head;

        auto mid = get_mid(head);//使用快慢指针获取链表的中间节点，并且根据中间节点将链表一分为二
        auto l = merge_sort(head);//递归排序左边区间
        auto r = merge_sort(mid);//递归排序右边区间
        
        return merge(l, r);//合并链表
    }
};


//非递归版，时间复杂度O(nlogn)，空间复杂度O(1)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) n++;//获取链表长度

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        for (int i = 1; i < n; i = i * 2) {//没次合并的区间长度
            auto cur = dummy;
            for (int j = 1; j <= n; j += 2 * i) {//合并的两段区间，第一段区间的起始位置j，第二段的起始区间为i+j
                auto p = head, q = p;
                for (int k = 0; k < i && q; k++) q = q->next;//q为第二段的起始区间
                
                int x = 0, y = 0;
                while (x < i && y < i && p && q) {//归并过程，与普通归并不同，需要使用x,y记录两段的长度，合并的长度需要小于i
                    if (p->val <= q->val) cur = cur->next = p, p = p->next, x++;
                    else cur = cur->next = q, q = q->next, y++;
                }
                while (x < i && p) cur = cur->next = p, p = p->next, x++;
                while (y < i && q) cur = cur->next = q, q = q->next, y++;
                head = q;//head等于下一段要合并的起始位置
            }
            cur->next = nullptr;
            head = dummy->next;//链表头
        }
        return dummy->next;
    }
};

