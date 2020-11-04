//方法一：迭代时间复杂度O(n)
//定义一个哑结点作为合并后链表的头节点，开始时令cur指向哑结点，依次遍历两个链表，
//每次将两个链表中较小的那个加入到cur后面，移动cur和已经使用过的节点，最后如果某个链表还要剩余则
//加入到cur末尾即可
Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return nullptr;
        if (!l1 || !l2) return l1 ? l1 : l2;

        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {//l1较小
                cur->next = l1;//将较小的点连接到cur后面
                cur = cur->next;//更新cur
                l1 = l1->next;//比较l1下一个节点
            }
            else {//l2较小
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if (!l1) cur->next = l2;//剩余部分连接到末尾即可
        else cur->next = l1;
        return dummy->next;
    }
};