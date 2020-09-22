class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans;
        for (int j = 0; j < nums.size(); j++) {
            if (hash.count(target - nums[j])) {
                int i = hash[target - nums[j]];
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
            hash[nums[j]] = j;
        }
        return ans;
    }
};