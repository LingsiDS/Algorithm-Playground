//i从0扫描一遍，维护当前可以跳到的最远位置j=max(j, i+nums[i])，如果j<i说明当前位置不可达，时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {//从前往后扫描数组
            if (j < i) return false;//如果当前位置超过了可以跳到的最大位置，返回false表示不可以走到
            j = max(j, i + nums[i]);//可以到达当前位置i，则更新j，j表示可以跳到的最大位置
        }
        return true;//遍历完说明可以走到
    }
};

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


