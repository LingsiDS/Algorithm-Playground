//插入排序，第二遍，2020年11月20日 16:39:37
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head) return head;
        ListNode *dumy = new ListNode(-1);
        dumy->next = head;
        
        ListNode *pre = head;
        head = head->next;
        while (head) {
            if (head->val >= pre->val) {
                head = head->next;
                pre = pre->next;
                continue;
            }
            ListNode *insertPos = dumy;
            while (insertPos->next && insertPos->next->val < head->val) {
                insertPos = insertPos->next;
            }
            //插入操作
            pre->next = head->next;
            head->next = insertPos->next;
            insertPos->next = head;
            head = pre->next;
        }
        return dumy->next;
    }
};

//时间复杂度O(n^2)，空间复杂度O(1)
//如果cur->val 比 pre->val 大，可以不用进行插入，这样对于大致有序的数据可以更快
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode;
        dummy->next = head;

        ListNode *cur = head->next, *pre = head;//cur为当前遍历的节点，pre为cur的前驱节点
        while (cur) {
            if (pre->val <= cur->val) {//如果已经有序，可以不用从头开始遍历
                pre = cur;//更新pre和cur
                cur = cur->next;
                continue;
            }

            ListNode *t = dummy;//t指针从头开始查找cur应该插入的点

            //比较t->next->val 和 cur->val这样停下来时，t后面就是cur的插入位置，这里是小于号，t的位置不超过cur
            while (t->next && t->next->val < cur->val) t = t->next;
            
            //将cur插入到t后面
            pre->next = cur->next;
            cur->next = t->next;
            t->next = cur;

            cur = pre->next;//更新cur，因为删除了一个点，不用更新pre
        }
        return dummy->next;
    }
};