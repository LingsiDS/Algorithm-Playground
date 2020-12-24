//排序，排序后，超过数组一半的数一定在中间。
//证明：最坏情况下为超过一般的数是数组中最大或最小的数，因为该数出现次数超过一半，故该数一定在中间

//时间复杂度O(nlogn)，空间复杂度O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};


//方法二：哈希表，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxV = -1, maxCnt;
        for (auto a: nums) {
            mp[a]++;
            if (mp[a] > maxCnt) {
                maxCnt = mp[a];
                maxV = a;
            }
        }
        return maxV;
    }
};

//投票法，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int votes = 0, mj = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (mj == 0) mj = nums[i];
            if (nums[i] == mj) votes++;
            else {
                votes--;
                if (votes == 0) mj = 0;
            }
        }
        return mj;
    }
};