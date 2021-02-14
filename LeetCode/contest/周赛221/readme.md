#### [1704. 判断字符串的两半是否相似](https://leetcode-cn.com/problems/determine-if-string-halves-are-alike/)

题意：判断给定的字符串两半中元音字符出现的次数是否相同

思路：遍历字符串的两边，统计其中元音字符出现的次数分别为`cnt1`，`cnt2`，最后返回`cnt1==cnt2`

```c++
class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> st{'a','e','i','o','u','A','E','I','O','U'};
        int mid = s.size() / 2;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0, j = 0; i < mid; i++, j++) {
            if (st.count(s[i])) cnt1++;
            if (st.count(s[mid + j])) cnt2++;
        }
        return cnt1 == cnt2;
    }
};
```

#### [1705. 吃苹果的最大数目](https://leetcode-cn.com/problems/maximum-number-of-eaten-apples/)

**题意**：有一棵特殊的苹果树，一连 `n` 天，每天都可以长出若干个苹果。在第 `i` 天，树上会长出 `apples[i]` 个苹果，这些苹果将会在 `days[i]` 天后（也就是说，第 `i + days[i]` 天时）腐烂，变得无法食用。也可能有那么几天，树上不会长出新的苹果，此时用 `apples[i] == 0` **且** `days[i] == 0` 表示。

你打算每天 **最多** 吃一个苹果来保证营养均衡。注意，你可以在这 `n` 天之后继续吃苹果。

给你两个长度为 `n` 的整数数组 `days` 和 `apples` ，返回你可以吃掉的苹果的最大数目

```
示例 1：

输入：apples = [1,2,3,5,2], days = [3,2,1,4,2]
输出：7
解释：你可以吃掉 7 个苹果：
- 第一天，你吃掉第一天长出来的苹果。
- 第二天，你吃掉一个第二天长出来的苹果。
- 第三天，你吃掉一个第二天长出来的苹果。过了这一天，第三天长出来的苹果就已经腐烂了。
- 第四天到第七天，你吃的都是第四天长出来的苹果。
```



**思路**：考虑当前为第`i`天，且手中有多个不同时间腐烂的苹果，那么这一天应该吃掉哪个苹果呢？直觉告诉我们，**应该吃掉最快腐烂的苹果**，因为更慢腐烂的苹果可以留到更后的时间点再吃，而快要腐烂的苹果只有先吃才能使最后腐烂“浪费”的苹果最少。根据这个思路，要根据腐烂的时间维护苹果的**“顺序”**，且每次只吃最快腐烂的那个苹果，所以可以使用根据腐烂时间维护**优先队列**，使用小顶堆，每次从堆顶取得最快腐烂的苹果，如果没有腐烂，则吃掉一个最快腐烂的苹果。

**细节**：注意，不能将所有苹果先加入队列再吃，这样会导致第`i`天可能会吃掉第`j`天的苹果，`i<j`，实际上第`j`天的苹果在第`i`天还不存在。

```c++
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = apples.size();
        
        int d = 0;
        int res = 0;
        for (int i = 0; i < n; i++, d++) {
            if (apples[i] != 0 && days[i] != 0) //放入苹果
                pq.push({i + days[i], apples[i]});
            while (pq.size()) {
                auto t = pq.top();pq.pop();
                if (t.first <= d) continue;//苹果已经腐烂
                if (t.first > d) {//说明有还未腐烂的苹果
                    if (t.second == 0) continue;
                    res++;//吃一个苹果
                    t.second--;
                    if (t.second != 0)
                        pq.push(t);//吃完之后修改苹果数量重新入队
                    break;
                }
            }
        }
		
        while (pq.size()) {//在第n天之后，还可以继续吃苹果
            auto t = pq.top(); pq.pop();
            if (t.first <= d) continue;
            if (t.first > d) {//一定可以吃苹果
                int cnt = min(t.first - d, t.second);//一次尽可能吃最多最快腐烂的苹果
                d += cnt;
                res += cnt;
            }
        }
        return res;
    }
};
```



#### [1706. 球会落何处](https://leetcode-cn.com/problems/where-will-the-ball-fall/)

题目见原链接

思路：`grid`为整个箱子的状态，大小为`m x n`，对于每一个格子内的球，模拟其走过的路径，这样时间复杂度为`O(m*n)`，需要注意的一点是，假设当前小球位于第`i`行，第`j`列，要根据`grid[i][j]`的情况来判断是要和`grid[i][j + 1]`还是和`grid[i][j - 1]`进行比较，如果`grid[i][j]`向右下方倾斜则要和`grid[i][j + 1]`比较，反之需要和`grid[i][j]`比较，如下面代码第13行和第20行。

```c++
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            int x = 0, y = i;//x，y为起始的位置
            while (x < m && y < n) {
                int z = grid[x][y];
                if (z == 1) {//如果当前单元格向右
                    if (y == n - 1) break;  //被右边界卡住
                    if (grid[x][y + 1] == 1) {
                        x++;
                        y++;
                    }else break;//在中间某个位置被卡住
                }
                if (z == -1) {//如果当前单元格向左
                    if (y == 0) break;//被左边界卡住
                    if (grid[x][y - 1] == -1) {
                        x++;
                        y--;
                    } else break;//在中间某个位置被卡住
                }
            }
            if (x == m) res[i] = y;//到达了底部
        }
        return res;
    }
};
```



#### [1707. 与数组中元素的最大异或值](https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array/)

**题意**：

给你一个由非负整数组成的数组 `nums` 。另有一个查询数组 `queries` ，其中 `queries[i] = [xi, mi]` 。

第 `i` 个查询的答案是 `xi` 和任何 `nums` 数组中不超过 `mi` 的元素按位异或`（XOR）`得到的最大值。换句话说，答案是 `max(nums[j] XOR xi)` ，其中所有 `j` 均满足 `nums[j] <= mi` 。如果 `nums` 中的所有元素都大于 `mi`，最终答案就是 `-1` 。

返回一个整数数组 `answer` 作为查询的答案，其中 `answer.length == queries.length` 且 `answer[i]` 是第 `i` 个查询的答案。

```
示例 1：

输入：nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
输出：[3,3,7]
解释：
1) 0 和 1 是仅有的两个不超过 1 的整数。0 XOR 3 = 3 而 1 XOR 3 = 2 。二者中的更大值是 3 。
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
```

思路：首先这题的思路基于一个经典的例题，[421. 数组中两个数的最大异或值](https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/)，这题是求给定一个数`ai`和数组中任意一个数`aj`异或，所得的值最大为多少？首先考虑这个问题如何求解，考虑异或运算的性质，**两个相反的位异或必定为1**，基于这样的性质，如果`aj`的高位和`ai`不同，那么其异或之后所得结果中，该位必定为1，然后使用**贪心策略**，最后`aj`与`ai`异或后所得值最大的`aj`一定具有这样的性质，**其二进制表示的高位尽可能的和ai的二进制表示的对应位不同**，这样的`aj`就是其**二进制表示的前缀尽可能和ai的二进制表示的对应位不同**，可以使用**Trie树**存储每个数的二进制表示前缀，查找异或结果的最大值时，就是在Trie数中尽可能走一条和`ai`二进制表示相反的路径。

这题在上一题中额外添加了一个限制，就是`aj`并不是数组中的所有数，而是小于某个数`xi`，可以通过**离线处理**的方法将这个问题转化为上一个问题。具体做法就是将所有**查询按`xi`排序**，当查询到`xi`时，**把数组中所有小于`xi`的`aj`插入Trie树中**，这样这个问题就等价于上一个问题，转化过程如下面的代码第49行。

```c++
static const int N = 1e5+10;
struct Node {
    int num, m, idx;
    bool operator < (Node &r) {
        return m < r.m;
    }
}q[N];

class Solution {
public:
    int son[31*N][2], idx = 0;
    void insert(int x) {//Trie的插入
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int u = x >> i & 1;
            if (!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
    }

    int query(int x) {//Trie查找算法，返回Trie中任意数与x异或结果的最大值
        if (!idx) return -1;
        int p = 0, ret = 0;
        for (int i = 30; i >= 0; i--) {
            int u = x >> i & 1;
            if (son[p][!u]) {
                ret |= 1 << i;
                p = son[p][!u];
            } else {
                p = son[p][u];
            }
        }
        return ret;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();

        sort(nums.begin(), nums.end());//nums排序

        for (int i = 0; i < queries.size(); i++) {//queries按xi排序
            q[i] = {queries[i][0], queries[i][1], i};
        }
        sort(q, q + m);

        vector<int> answer(m, -1);
        int idx = 0;
        for (int i = 0; i < m; i++) {
            while (idx < n && nums[idx] <= q[i].m) insert(nums[idx++]);//离线处理
            answer[q[i].idx] = query(q[i].num);//查询
        }
        return answer;
    }
};
```

