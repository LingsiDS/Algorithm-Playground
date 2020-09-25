/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre = new ListNode(0);
        //让pre指针指向一个虚拟节点，并且pre->next = head，这一步的目的是删除某个节点时，需要知道该节点的前驱，pre即为要删除节点的前驱
        pre->next = head;   
        
        //使用双指针算法，首先将first指针定位到从头开始第n个元素，当first指向末尾节点时，pre执行待删除节点的前驱
        ListNode *first = head;
        int cnt = n - 1;//指向第n个其实只要移到n-1次
        while (first && cnt) {//让first指向第n个节点
            first = first->next;
            cnt--;
        }
        
        //遍历链表直到first指向末尾
        while (first->next) {
            first = first->next;
            pre = pre->next;
        }
        if (pre->next != head)
            pre->next = pre->next->next;
        else head = head->next;//删除第一个元素
        return head;
    }
};