class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return n;
        int idx = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) continue;
            else nums[idx++] = nums[i]; 
        }
        return idx;
    }
};