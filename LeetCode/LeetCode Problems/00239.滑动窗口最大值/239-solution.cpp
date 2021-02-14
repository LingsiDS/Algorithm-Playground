//滑动窗口经典题，使用双端队列，存储下标，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (dq.size() && i - dq.front() >= k) dq.pop_front();
            while (dq.size() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i + 1 >= k) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};