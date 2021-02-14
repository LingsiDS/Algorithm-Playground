# 第222场周赛题解

注：题目来源[LeetCode](https://leetcode-cn.com/problemset/all/)

#### [1710. 卡车上的最大单元数](https://leetcode-cn.com/problems/maximum-units-on-a-truck/)

请你将一些箱子装在**一辆卡车**上。给你一个二维数组`boxTypes`，其中 `boxTypes[i] = [numberOfBoxes_i, numberOfUnitsPerBox_i]` ：

- `numberOfBoxes_i`是类型 `i` 的箱子的数量。
- `numberOfUnitsPerBox_i` 是类型`i`每个箱子可以装载的**单元**数量。

整数`truckSize`表示卡车上可以装载**箱子**的**最大数量** 。只要箱子数量不超过 `truckSize` ，你就可以选择**任意箱子**装到卡车上。

返回卡车可以装载**单元**的**最大**总数。

```
示例 1：

输入：boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
输出：8
解释：箱子的情况如下：
- 1 个第一类的箱子，里面含 3 个单元。
- 2 个第二类的箱子，每个里面含 2 个单元。
- 3 个第三类的箱子，每个里面含 1 个单元。
可以选择第一类和第二类的所有箱子，以及第三类的一个箱子。
单元总数 = (1 * 3) + (2 * 2) + (1 * 1) = 8
```

**题意**：题目给出一个箱子的数组，并且每个箱子可以装若干个单元，给定卡车可以装的箱子个数，问可以装载**单元**的最大总数。可以想象为每个箱子固定大小，卡车可以装下`truckSize`个箱子，每个大小相同的箱子被划分为不同数量的单元，最后问`truckSize`个箱子最大的单元总数。

**思路**：经过题意的分析可以看出卡车能够装载箱子的个数是一定的，可以装`truckSize`个，要使总的单元总数最大，选择箱子装入卡车时，应该选择单元总数最大的箱子装入卡车。可以使用**贪心策略**，将所有箱子按单元数从大到小进行排序，每次选择剩余箱子中单元数最大的箱子装入卡车，直到选择满`truckSize`个箱子。

```c++
//O(nlogn)
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>&a, vector<int>&b){
            return a[1] > b[1];//从小到大排序
        });

        int res = 0, i = 0;
        while (truckSize > 0) {
            if (i >= boxTypes.size()) break;//箱子耗尽
            int cnt = min(boxTypes[i][0], truckSize);//可以装载第i类箱子的个数
            res += boxTypes[i++][1] * cnt;
            truckSize -= cnt;
        }
        return res;
    }
};
```



#### [1711. 大餐计数](https://leetcode-cn.com/problems/count-good-meals/)

**大餐**是指**恰好包含两道不同餐品**的一餐，其**美味程度之和**等于**2的幂**。

你可以搭配**任意**两道餐品做一顿大餐。

给你一个整数数组 `deliciousness` ，其中 `deliciousness[i]` 是第`i`道餐品的美味程度，返回你可以用数组中的餐品做出的不同**大餐**的数量。结果需要对 $10^9 + 7$ 取余。

注意，只要餐品下标不同，就可以认为是不同的餐品，即便它们的美味程度相同。

```
示例 1：
输入：deliciousness = [1,3,5,7,9]
输出：4
解释：大餐的美味程度组合为 (1,3) 、(1,7) 、(3,5) 和 (7,9) 。
它们各自的美味程度之和分别为 4 、8 、8 和 16 ，都是 2 的幂。

示例 2：
输入：deliciousness = [1,1,1,3,3,3,7]
输出：15
解释：大餐的美味程度组合为 3 种 (1,1) ，9 种 (1,3) ，和 3 种 (1,7) 。
```

- 1 <= `deliciousness.length` <= $10^5$
- 0 <= `deliciousness[i]` <= $2^{20}$

**思路**：根据数据规模$10^5$可以知道，有效算法的时间复杂度至少为$O(nlogn)$。首先考虑暴力做法，暴力做法枚举所有两个数的组合，其时间复杂度为$O(n^2)$，根据两数之和的经验，可以使用哈希表减少一重循环，与两数之和不同的是，这里不是判断两数之和是否等于某个具体的数，而是判断**两数之和是否属于某个集合**——两数之和为2的幂。同时注意到0 <= `deliciousness[i]` <= $2^{20}$，也就是说`deliciousness`中两个数相加的和最大为$2^{21}$，基于2的幂次集合的又穷性（22个），可以枚举两个数之和是否等于该集合中的每个元素。最后使用哈希表加上枚举集合中的元素，其时间复杂度为$O(nlogn)$

**注意**：根据数据范围0 <= `deliciousness[i]` <= $2^{20}$应该明确两数之和最大为$2^{21}$，第一次写时没意识到写成了$2^{20}$然后WA了，并且测试用例被隐藏了，最后查了半小时才通过。

```c++
//O(nlogn)
class Solution {
public:
    const int mod = 1e9 + 7;
    int countPairs(vector<int>& deliciousness) {
        vector<int> pw;
        for (int i = 0; i <= 21; i++) {
            pw.push_back(pow(2, i));
        }
        long long res = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < deliciousness.size(); i++) {
            for (int j = 0; j <= 21; j++) {
                int left = pw[j] - deliciousness[i];
                if (hash.count(left)) {
                    res = (res + hash[left]) % mod;//这里可以多考虑会不会爆int，这里不会
                }
            }
            hash[deliciousness[i]]++;
        }
        return res;
    }
};
```



#### [1712. 将数组分成三个子数组的方案数](https://leetcode-cn.com/problems/ways-to-split-array-into-three-subarrays/)

我们称一个分割整数数组的方案是 **好的** ，当它满足：

- 数组被分成三个 **非空** 连续子数组，从左至右分别命名为 `left` ， `mid` ， `right` 。
- `left` 中元素和小于等于 `mid` 中元素和，`mid` 中元素和小于等于 `right` 中元素和。

给你一个 **非负** 整数数组 `nums` ，请你返回 **好的** 分割 `nums` 方案数目。由于答案可能会很大，请你将结果对 $10^9 + 7$ 取余后返回。

```
示例 1：
输入：nums = [1,1,1]
输出：1
解释：唯一一种好的分割方案是将 nums 分成 [1] [1] [1] 。

示例 2：
输入：nums = [1,2,2,2,5,0]
输出：3
解释：nums 总共有 3 种好的分割方案：
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]
```

**数据范围**

- 3 <= `nums.length` <= $10^5$
- 0 <= `nums[i]` <= $10^4$

**思路**：首先根据数据范围可以知道该题有效算法的时间复杂度的上限为$O(nlogn)$。从暴力思路出发，枚举两个分界点`i`和`j`， `i < j`，两个分界点将数组分为三个区域，使用前缀和可以O(1)时间内计算每个区间的和，计算是否符合`left <= mid <= right`，这样暴力算法的时间复杂度为$O(n^2)$会超时。优化思路为：先枚举一个分界点，假设是`i`，对于分界点`j`，其下限由`left <= mid`限制，其上限由`mid <= right`限制，并且数组中所有数为正数，**区间和具有单调性**，所以可以使用**二分查找**得到`j`的上下限范围，假设分别为`lo`和`hi`，则当前满足条件的元素个数为`hi - lo + 1`，枚举完所有`i`得到最终答案。

另外该题还有时间复杂度为O(n)的双指针解法。

```c++
//O(nlogn)
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n + 2, 0);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];//前缀和

        int res = 0, mod = 1e9+7;
        for (int i = 1; i <= n - 2; i++) {//枚举第一个分界点
            int l = i + 1, r = n - 1;
            while (l < r) {//二分第二个分界点的左边（下限）
                int mid = l + r >> 1;
                if (s[i] <= s[mid] - s[i]) r = mid;//根据left <= mid的限制，二分mid的左边界
                else l = mid + 1;
            }
            int lo = l;//第二个分界点的最左边
            l = i + 1, r = n - 1;
            while (l < r) {//二分第二个分界点的右边（上限）
                int mid = l + r + 1>> 1;
                if (s[mid] - s[i] <= s[n] - s[mid]) l = mid;//根据mid <= right的限制，二分mid的右边界
                else r = mid - 1;
            }
            int hi = l;//第二个分界点的最右边
            if (lo == hi &&  s[i] <= s[hi] - s[i] && s[hi] - s[i] <= s[n] - s[hi]) res = (res + 1 % mod);//如果子数组mid只有一个数
            if (lo < hi) res = (res + (hi - lo) + 1) % mod;//统计区间个数
        }
        return res;
    }
};
```



#### [1713. 得到子序列的最少操作次数](https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/)

给你一个数组 `target` ，包含若干 **互不相同** 的整数，以及另一个整数数组 `arr` ，`arr` 可能 包含重复元素。

每一次操作中，你可以在 `arr` 的任意位置插入任一整数。比方说，如果 `arr = [1,4,1,2]` ，那么你可以在中间添加 `3` 得到 `[1,4,3,1,2]` 。你可以在数组最开始或最后面添加整数。

请你返回 **最少** 操作次数，使得 `target` 成为 `arr` 的一个子序列。

一个数组的 **子序列** 指的是删除原数组的某些元素（可能一个元素都不删除），同时不改变其余元素的相对顺序得到的数组。比方说，`[2,7,4]` 是 `[4,2,3,7,2,1,4]` 的子序列，但 `[2,4,2]` 不是子序列。

```
示例 1：

输入：target = [5,1,3], arr = [9,4,2,3,4]
输出：2
解释：你可以添加 5 和 1 ，使得 arr 变为 [5,9,4,1,2,3,4] ，target 为 arr 的子序列。
```

**数据范围**：

- 1 <= `target.length`, `arr.length` <= $10^5$
- 1 <= `target[i]`, `arr[i]` <= $10^9$
- `target` 不包含任何重复元素。

**思路**：首先将该问题转化为最长公共子序列问题。如果我们求出`target`和`arr`的**最长公共子序列**长度为`len`，那么最少的添加次数为`target.size() - len`。同时注意到时间复杂度要求算法至少为$O(nlogn)$级别，根据条件`target`中**不包含任何重复元素**可以将最长公共子序列问题转化为**最长上升子序列**问题。做法如下，首先遍历`arr`数组，对于任意一个元素`arr[i]`，如果其在`target`中出现过，且其下标为`idx`，则将`idx`加入到新数组`a`中，这样只要求`a`数组的最长上升子序列就得到了`target`和`arr`的最长公共子序列，而求最长上升子序列有$O(nlogn)$的解法。

```c++
//O(nlogn)
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> hash;
        for (int i = 0; i < target.size(); i++) hash[target[i]] = i;
        
        vector<int> a;
        for (int i = 0; i < arr.size(); i++)//将问题从LCS转化为LIS
            if (hash.count(arr[i]))
                a.push_back(hash[arr[i]]);
        
        //最长上升子序列O(nlogn)
        int len = 0;//最长上升子序列的最大长度
        vector<int> q(a.size() + 1, 0); //q[i]存储的是最长上升子序列的长度为i的所有上升子序列中最后一个元素的最小值
        q[0] = INT_MIN;//哨兵
        for (int i = 0; i < a.size(); i++) {
            int l = 0, r = len;//二分范围
            while (l < r) {//二分arr[i]最佳可以接到哪个元素后面使得，LIS的长度增大
                int mid = l + r + 1 >> 1;
                if (q[mid] < a[i]) l = mid;
                else r = mid - 1;
            }
            len = max(len, r + 1);//更新最长上升子序列的长度
            q[r + 1] = a[i]; //a[i]一定大于q[r+1]，用a[i]更新q数组
        }
        return target.size() - len;//target长度减去最长公共子序列的长度
    }
};
```

