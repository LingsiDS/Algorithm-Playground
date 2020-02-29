给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的**每个数字在每个组合中只能使用一次**。

说明：

所有数字（包括目标数）都是正整数。
解集**不能包含重复的组合**。 
示例 1:

`输入: candidates = [10,1,2,7,6,1,5], target = 8,`
`所求解集为:`
`[`
  `[1, 7],`
  `[1, 2, 5],`
  `[2, 6],`
  `[1, 1, 6]`
`]`

示例 2:

`输入: candidates = [2,5,2,1,2], target = 5,`
`所求解集为:`
`[`
  `[1,2,2],`
  `[5]`
`]`

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



**解答**：这题为39题的续题，与39题不同的是，每个数字在每个组合中只能使用一次，同样解集不允许出现重复的组合。

以示例2为例，按39题中的解法，排序后，数组为`candidates = [1,2,2,2,5]，target=5`。分别取下标在排序后的数组中为[0,1,1],[0,1,2],[0,1,3]中的数都能组成解[1,2,2]，都能满足和等于target，因为39题中每个元素可以重复使用，这几种解都是是合理的，而该题中只有下标为[0,1,2]的解为合理的。

所以该题在39题的基础上需要考虑排除这种解即可。下面第21行代码便是在搜索时同一层次时，跳过相同的数。

```c++
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
```

