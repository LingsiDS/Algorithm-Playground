class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //先排序，当nums中有重复元素时，方便去重，每个元素只使用一次
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i-1]) continue;//去重
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;//去重
                for (int k = j + 1, r = nums.size() - 1; k < r; k++) {//双指针算法
                    if (k > j + 1 && nums[k] == nums[k-1]) continue;//去重
                    while (k < r && nums[i] + nums[j] + nums[k] + nums[r] > target) r--;
                    
                    //while循环结束，如果r==k，r和k指向同一个数，不能使用同一个数，continue
                    if (k == r) continue;

                    //如果执行到这，说明nums[i] + nums[j] + nums[k] + nums[r] <= target，检测是否等于target
                    int sum = nums[i] + nums[j] + nums[k] + nums[r];
                    if (sum == target) res.push_back({nums[i], nums[j], nums[k], nums[r]});
                    //如果nums[i] + nums[j] + nums[k] + nums[r] < target，若还想找到等于target的四个数，nums[k]必须增大，所以进入下一层循环即可
                }
            }
        }
        return res;
    }
};


//排序+两重循环+双指针+剪枝
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());//从小到大排序
        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i-1] == nums[i]) continue;//去重
            
            if (i+3 < nums.size() && nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) 
                break;//剪枝
            if (nums[i] + nums[nums.size()-1] + nums[nums.size()-2] + nums[nums.size()-3] < target) 
                continue;//剪枝

            for (int j = i+1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j-1] == nums[j]) continue;//去重
                
                if (j+2 < nums.size() && nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) 
                    break;//剪枝,最小都比target大
                if (nums[i] + nums[j] + nums[nums.size()-1] + nums[nums.size()-2] < target) 
                    continue;//剪枝

                int k = j + 1, m = nums.size() - 1;
                for (; k < m; k++) {
                    if (k > j + 1 && nums[k-1] == nums[k]) continue;//去重

                    while (k < m && nums[i] + nums[j] + nums[k] + nums[m] > target) {
                        m--;
                    }
                    if (k==m) break;
                    //cout << nums[i] + nums[j] + nums[k] + nums[m] << endl;
                    if (nums[i] + nums[j] + nums[k] + nums[m] == target) 
                        res.push_back({nums[i], nums[j], nums[k], nums[m]});
                }
            }
        }
        return res;
    }
};