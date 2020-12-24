//lc.295 两个堆
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (pq1.empty()) pq1.push(num);
        else if (num > pq1.top()) {
            pq2.push(num);
            if (pq2.size() > pq1.size()){
                pq1.push(pq2.top());
                pq2.pop();
            } 
        } else {
            pq1.push(num);
            if (pq1.size() - pq2.size() > 1) {
                pq2.push(pq1.top());
                pq1.pop();
            }
        }
    }
    
    double findMedian() {
        int n = pq1.size() + pq2.size();
        if (n & 1) return pq1.top();
        else return (pq1.top() + pq2.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */