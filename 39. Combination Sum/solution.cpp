class Solution {
public:
    vector<vector<int> > rst;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());//先对数组排序，顺序搜索结果
        dfs(candidates, target, 0, {}, 0);
        return rst;
    }

    void dfs(vector<int>& data, int target, int sum, vector<int> path, int index) {
        if (sum == target) rst.push_back(path);
        for (int i = index; i < data.size(); i++) {
            sum += data[i];
            path.push_back(data[i]);
            if (sum <= target) dfs(data, target, sum, path, i);
            if (sum > target) break;//data为有序数组，此时sum>target后续一定不符合，剪枝
            sum -= data[i];//状态回溯
            path.pop_back();
        }
        
    }
};