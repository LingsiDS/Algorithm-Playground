//设计题，使用两个堆pq1, pq2，一个存放前半段数据，一个存放后半段数据，
//添加元素时，保证pq1的堆顶是中位数，如果是偶数，保证中间两个数一个在pq1堆顶，一个在pq2堆顶
class MedianFinder {
public:
    /** initialize your data structure here. */
    int n = 0;
    priority_queue<int, vector<int>, less<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    
    MedianFinder() {

    }
    
    void addNum(int num) {//添加元素时，如果是奇数保证pq1的堆顶是中位数，如果是偶数，保证中间两个数一个在pq1堆顶，一个在pq2堆顶
        n++;
        if (pq1.empty()) pq1.push(num);
        else {
            if (num >= pq1.top()) {//属于后半段数据，将num放入pq2
                pq2.push(num);
                if (pq2.size() > pq1.size()) {//pq2最多和pq1元素个数一样多
                    pq1.push(pq2.top());
                    pq2.pop();
                } 
            } else {//num属于前半段的数据
                pq1.push(num);
                if (pq1.size() - pq2.size() > 1) {//pq1最多比pq2多1个元素
                    pq2.push(pq1.top());
                    pq1.pop();
                }
            }
        }
    }
    
    double findMedian() {
        if (n & 1) return pq1.top();
        else return (pq1.top() + pq2.top()) / 2.0;
    }
};
