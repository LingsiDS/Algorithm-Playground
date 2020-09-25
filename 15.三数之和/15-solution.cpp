class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i-1]) continue;//去除重复元素
            for (int j = i + 1, k = nums.size()-1; j < k; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;//去除重复元素
                //找到满足nums[i] + nums[j] + nums[k - 1] >= 0，的最小值
                while (j < k - 1 && nums[i] + nums[j] + nums[k - 1] >= 0) k--;//如果k-1，满足，k--
                if (nums[i] + nums[j] + nums[k] == 0) res.push_back({nums[i], nums[j], nums[k]});//找到答案
            }
        }
        return res;
    }
};

//使用哈希表不容易去重