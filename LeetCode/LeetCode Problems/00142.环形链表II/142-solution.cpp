//数学分析题，关键点：先找相遇点，然后从相遇点和头节点同时走，再次相遇时即为入口点
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        ListNode *slow = head, *fast = head;//从同一点出发
        int first = 1;//第一次slow == fast
        while (slow != fast || first) {//寻找相遇点
            first = 0;
            if (!fast || !fast->next || !fast->next->next) return nullptr;//链表为空
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;
        while (slow != fast) {//一个指针从head走，另一个指针从相遇点走，再次相遇时，两指针必指向入口点
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};