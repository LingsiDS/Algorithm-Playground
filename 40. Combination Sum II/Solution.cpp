class Solution {
public:
    vector<vector<int>> ans;
    int uniqueSize;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, 0, {});
        return ans;
    }

    void dfs(vector<int>& data, int sum, int target, int index, vector<int> path) {
        for (int i = index; i < data.size(); ++i) {
            sum += data[i];
            path.push_back(data[i]);
            if (sum == target) {
                ans.push_back(path);
                return;//找到第一个符合条件的即可返回，防止重复
            }
            if (sum < target) {
                dfs(data, sum, target, i+1, path);//和39题不同之处为下一次迭代从i+1开始
                while (i+1 < data.size() && data[i] == data[i+1]) i++;//搜索树中，同一层跳过相同的数，防止出现重复
            }
            if (sum > target) return;//剪枝，数组是升序排序的，如果sum>target，那么之后的数一定不符合
            //回溯状态
            sum -= data[i];
            path.pop_back();

        }
    }
};