给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字**可以无限制重复**被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]

示例 2:
输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

**KEY:**
1、最暴力搜索的解法为DFS，搜索candidates数组，每一层搜索从[0 - size-1]，假设candidates数组的大小为n，则时间复杂度为O(n^n)，并且不容易去重
```c++
void dfs(vector<int>& data, int target, int sum, vector<int> ans) {
        if (sum == target) {
            bool same = 0;
            sort(ans.begin(), ans.end());
            for (int i = 0; i < rst.size(); i++) {//去除重复的组合
                if (ans.size() == rst[i].size()) {
                    int j;
                    for (j = 0; j < rst[i].size(); j++) {
                        if (rst[i][j] != ans[j]) break;
                    }
                    if (j == rst[i].size()) same = 1;
                }
            }
            if (!same) rst.push_back(ans);
            return;
        }
        for (int i = 0; i < data.size(); i++) {
            sum += data[i];
            ans.push_back(data[i]);
            if (sum <= target) dfs(data, target, sum, ans);//递归搜索
            ans.pop_back();//回溯状态
            sum -= data[i];
        }
    }
```

2、第一种解法复杂度过高，可以先将candidates数组按升序排序，如数组[2,3,5]，target = 8，搜索时按顺序搜索。假设搜索过程的所有可能称为候选解，如[2,2,2,2]，[2,3,5]，其中前者满足和等于target，称为可行解。搜索候选解时，首先固定候选解的第一个数为数组中下标为0的数，之后**候选解的第二个数在数组中的下标大于等于（一个数允许多次重复）候选解第一个数在数组中的下标，依次类推，这样保证搜索出的解为升序排列**，能够有效去除重复解。并且当可行解的和大于target时，可以直接返回，这样能缩小搜索的空间，提升算法效率。

```c++
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
```