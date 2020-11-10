//快慢指针，时间复杂度O(n),空间O(1)，如果使用哈希表时间/空间复杂度O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*pre = new ListNode;
        pre->next = head;

        while (head && head->next) {
            pre = pre->next;
            head = head->next;
            if (head == pre) return true;       //存在环
            head = head->next;
            if (head == nullptr) return false;  //没有环
            if (head == pre) return true;       //存在环
        }
        return false;
    }
};