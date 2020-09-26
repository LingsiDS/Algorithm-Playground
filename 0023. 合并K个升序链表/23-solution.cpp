/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//朴素做法，k为链表个数，n为所有链表的节点数
//使用for循环查找当前最小节点，复杂度为log(k)，每个节点都需要查找总时间复杂度为nlog(k)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode;
        ListNode* res = head;
        while (lists.size()) {
            if (lists.size() == 1) {
                head->next = lists[0];
                return res->next;
            }
            int min_num = INT_MAX, min_idx = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == nullptr) {//空链表，
                    lists.erase(lists.begin() + i);//删除空链表
                    i--;//erase后当前位置为新的链表，i--，continue时i++，再次检测当前位置
                    continue;
                }
                if (lists[i]->val <= min_num) {//找所有链表中值最小的
                    min_num = lists[i]->val;
                    min_idx = i;
                }
            }
            
            if (min_idx != -1) {
                head->next = lists[min_idx];//指向当前值最小的节点
                lists[min_idx] = lists[min_idx]->next;//后移
                head = head->next;//后移
            }

            //该链表已经使用完
            if (min_idx != -1 && lists[min_idx] == nullptr) lists.erase(lists.begin() + min_idx);
        }
        return res->next;
    }
};



//使用优先队列，k为链表个数，n为所有链表的节点数
//时间复杂度：nlog(k)  找当前最小节点时，使用优先队列，每个节点都会插入队列，且优先队列里节点不超过k个
class Node{
public:
    int val;
    ListNode* ptr;
    Node(int v, ListNode* p): val(v), ptr(p) {}
};

//return true if a is considered to go before b in the strict weak ordering the function defines.
struct Cmp {
    bool operator() (Node l, Node r) {//重载Cmp为函数对象，小顶堆
        return l.val >= r.val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode;
        ListNode* res = head;
        
        priority_queue<Node, vector<Node>, Cmp> q;
        for (auto a: lists) {
            if (a) q.push({a->val, a});
        }

        while (!q.empty()) {
            auto f = q.top();
            q.pop();
            head->next = f.ptr;
            head = head->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        
        return res->next;
    }
};