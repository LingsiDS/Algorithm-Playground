class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //小顶堆，存储的是一对pair，pair第二个元素为数组中的某个数，pair的第一个元素为出现的次数，优先队列会按照pair的第一个元素维护有序性
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > heap;
        
        //哈希表中key：数组中的数，val为该数在数组中出现的次数
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }

        //m*O(logk) m为数组中不同数的个数
        for (auto &[num, cnt]: hash) {
            if (heap.size() < k) heap.push({cnt, num});
            else {
                if (cnt > heap.top().first) {
                    heap.pop();
                    heap.push({cnt, num});
                }
            }
        }
        vector<int> res;
        //klog(k)
        while (heap.size()) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    } 
};