//顺序遍历一遍链表，将链表存储到vector中，方便在O(1)的时间内访问到链表的某个元素
//然后从前往后选择下标之和为n-1的两对元素进行重构
//时间复杂度：遍历了一遍链表O(n)，空间复杂度：使用了vector存储链表O(n)
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> hash;

        while (head) {
            hash.push_back(head);
            head = head->next;
        }
        int n = hash.size();//一共有n个元素

        int idx = n - 1;//将两个下标和为idx的元素重构
        ListNode *pre = new ListNode;
        ListNode *res = pre;
        for (int i = 0; i < n / 2; i++) {
            ListNode *first = hash[i], *second = hash[idx-i];//两个节点的下标相加等于idx
            pre->next = first;
            first->next = second;
            pre = second;
        }
        if (n % 2) {//共有奇数个元素还剩下中间的一个元素没有加上
            pre->next = hash[n / 2];
            pre->next->next = nullptr;
        }else {
            pre->next = nullptr;
        }
    }
};