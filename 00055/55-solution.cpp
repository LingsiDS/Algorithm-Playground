//dfs  TLE
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;
        bool f = false;
        dfs(nums, 0, nums[0], f);
        return f;
    }

    void dfs(vector<int>& nums, int idx, int len, bool& f) {
        if (f || idx + len >= nums.size()-1) {
            f = true;
            return;
        }
        for (int l = 1; l <= len; l++) {
            dfs(nums, idx + l, nums[idx + l], f);
        }
    }
};


//dp 