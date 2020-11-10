//brute-force 时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] < nums[i]) cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};


//排序 时间复杂度O(nlongn)，空间复杂度O(n)
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());
        
        vector<int> res(nums.size(), 0);
        for (int i = 0; i < arr.size(); i++) {
            int idx = i - 1;
            while (idx >= 0 && arr[idx].first == arr[i].first) idx--;
            res[arr[i].second] = idx + 1;
        }
        return res;
    }
};

//计数排序，时间复杂度O(n+k)，k是nums[i]的范围，空间复杂度O(k)
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101, 0);

        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;//记录每个元素出现的次数
        }

        for (int i = 1; i < cnt.size(); i++) cnt[i] += cnt[i-1];

        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(nums[i] == 0 ? 0 : cnt[nums[i]-1]);
        }

        return res;
    }
};