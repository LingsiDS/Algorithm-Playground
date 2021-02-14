class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        if (n == 0) return {-1, -1};

        //在数组中寻找大于等于target的第一个位置
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] != target) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        res.push_back(l);

        //在数组中寻找大于target的第一个位置
        r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] == target) res.push_back(l);//如果没有大于target的元素，l可能等于target为结束位置
        else res.push_back(l - 1);//正常情况nums[l-1]为等于target的最后一个位置
        return res;
    }
};


//二刷时间：2020年12月1日 12:35:28 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int n = nums.size();
        vector<int> res;

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;//找第一个大于等于target的位置
            else l = mid + 1;
        }
        if (l > n || nums[l] != target) return {-1, -1};
        res.push_back(l);
        
        l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= target) l = mid;//找最后一个值为target的位置
            else r = mid - 1;
        }
        if (nums[l] != target) return {-1, -1};
        res.push_back(l);
        return res;
    }
};