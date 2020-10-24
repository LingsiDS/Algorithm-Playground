//遍历一遍链表使用vector存储各个节点，然后再vector上判断链表是否是回文的，时空复杂度O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<ListNode*> vec;
        while (head) {
            vec.push_back(head);
            head = head->next;
        }

        int j = vec.size()-1;
        int i = 0;
        while (i < j) {
            if (vec[i]->val != vec[j]->val) return false;
            i++;
            j--;
        }
        return true;
    }
};


//时间复杂度为O(n)，该版本空间复杂度为O(1)
//为了达到空间复杂度为O(1)，基本思想如下
//1.利用快慢指针找到链表的中点
//2.将链表中点之后的部分进行反转
//3.一个指针从头开始，另一指针从中点之后开始，遍历链表，判断它们的值是否相等
//4.为了不修改输入链表，判断完链表之后需要再次将链表中点之后的部分进行反转
class Solution {
public:
    //反转链表，并返回反转之后的链表的头结点的指针
    ListNode * reverseList(ListNode *pre, ListNode *cur) {
        while (cur) {
            ListNode *t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        return pre;
    }


    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;//没有元素或者只有一个元素

        ListNode *pre = new ListNode;
        pre->next = head;
        ListNode *slow, *fast;
        slow = pre, fast = head;
        while (fast) {//利用快慢指针找到链表的中间节点
            slow = slow->next;
            fast = fast->next;
            if (fast == nullptr) break;
            fast = fast->next;
            if (!fast) break;
        }

        ListNode *mid = slow;
        ListNode *p1 = slow->next, *p2;
        if (p1 == nullptr) return true;//只有一个节点
        p2 = p1->next;
        if (p2 == nullptr) return head->val == p1->val;//有两个节点
        
        ListNode * rev = reverseList(p1, p2);//反转链表
        mid->next->next = nullptr;
        mid->next = rev;

        fast = mid->next;
        slow = head;
        while (fast) {//判断链表是否是回文的
            if (slow->val != fast->val) return false;
            fast = fast->next;
            slow = slow->next;
        }

        rev =  reverseList(mid->next, mid->next->next);//不修改输入参数，需要再将链表反转
        mid->next = nullptr;
        mid = rev;

        return true;
    } 
};

