//堆，时间复杂度O(nlogk)，空间复杂度O(k)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) return{};
        priority_queue<int, vector<int>, less<int>> pq;

        for (int i = 0; i < arr.size(); i++) {
            if (pq.size() < k) pq.push(arr[i]);
            else {
                if (pq.top() > arr[i]) {
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }
        vector<int> res;
        while (pq.size()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};