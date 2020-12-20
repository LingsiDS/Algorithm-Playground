## [1678. 设计 Goal 解析器](https://leetcode-cn.com/problems/goal-parser-interpretation/)

题意：给定一个字符串只包含`"G"`, `"()"` `"(al)"`，根据转换规则将它们分别转换为`“G”`, `"o"`, `"al"`，返回转换后的字符串

思路：扫描替换即可，时间复杂度O(n)，空间O(1)

```c++
class Solution {
public:
    string interpret(string command) {
        string res;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G') res += 'G';
            else if (command[i] == '(' && i + 1 < command.size() && command[i + 1] == ')') {
                res += 'o';
                i++;
            } else {
                res += "al";
                i += 3;
            }
        }
        return res;
    }
};
```



## [1679. K 和数对的最大数目](https://leetcode-cn.com/problems/max-number-of-k-sum-pairs/)

给你一个整数数组 nums 和一个整数 k 。

每一步操作中，你需要从数组中选出和为 k 的两个整数，并将它们移出数组。

返回你可以对数组执行的最大操作数。

```
示例 1：
输入：nums = [1,2,3,4], k = 5
输出：2
解释：开始时 nums = [1,2,3,4]：
- 移出 1 和 4 ，之后 nums = [2,3]
- 移出 2 和 3 ，之后 nums = []
  不再有和为 5 的数对，因此最多执行 2 次操作。
```

思路：类似两数之和，找数组中有多少个数和为k，利用哈希表遍历，如果存在另一个数使得两个数和为k，则res++，否则将当前数加入哈希表

```c++
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> hash;

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (hash[k - nums[i]] > 0) {
                hash[k - nums[i]]--;
                res++;
            }
            else hash[nums[i]]++;
        }
        return res;
    }
};
```



## [1680. 连接连续二进制数字](https://leetcode-cn.com/problems/concatenation-of-consecutive-binary-numbers/)

**题意**：给你一个整数 `n` ，请你将 `1` 到 `n` 的二进制表示连接起来，并返回连接结果对应的 **十进制** 数字对 `1e9 + 7` 取余的结果。

**示例 1：**

```
输入：n = 3
输出：27
解释：二进制下，1，2 和 3 分别对应 "1" ，"10" 和 "11" 。
将它们依次连接，我们得到 "11011" ，对应着十进制的 27 。
```



**思路**：因为最后返回的就是10进制数，可以直接在十进制数上进行操作，只要**在十进制数上操作的结果和在二进制数上操作的结果相同即可**。假设现在的数为res，将res的二进制与i的二进制连接起来，等价于**将res的十进制右移x=get_bits(i)位，再和i相加**。`res = ((res << get_bits(i)) + i) % mod`; `get_bits(i)`为计算`i`的二进制表示有多少位。

`get_bits()`时间复杂度为`O(logn)`，算法整体时间复杂度为`O(nlogn)`，可以将求i的二进制位数的操作优化为`O(1)`，这样时间复杂度就是O(n)，见方法二。

```c++
//方法1，O(nlogn)
class Solution {
public:
    const int mod = 1e9 + 7;
    typedef long long LL;

    int get_bits(int x) {
        int ret = 0;
        while (x) {
            ret++;
            x >>= 1;
        }
        return ret;
    }
    
    int concatenatedBinary(int n) {
        LL res = 1;
        for (int i = 2; i <= n; i++) {
            res = ((res << get_bits(i)) + i) % mod;
        }
        return res;
    }
};

//方法2，O(n)
class Solution {
public:
    int concatenatedBinary(int n) {
        int shift = 0;//shift表示：当前枚举到的数i的二进制的位数
        long long res = 0;
        const int mod = 1e9+7;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) shift++;//发生进位，二进制位数增加
            res = ((res << shift) + i) % mod;
        }
        return res;
    }
};
```



## [1681. 最小不兼容性](https://leetcode-cn.com/problems/minimum-incompatibility/)



```c++
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size(), INF = 0x3f3f3f3f;
        vector<int> f(1 << n, INF);//f[i]表示集合i的不相容性和的最小值
        vector<int> g(1 << n);//如果i是合法的集合，g[i]表示i这个集合的不相容性

        for (int i = 1; i < 1 << n; i++) {//枚举所有nums的选择方案，共有2^n种
            g[i] = -1;
            if (__builtin_popcount(i) == n / k) {//i这个集合1的个数是否合法
                
                vector<int> freq(16 + 1, 0);//freq[i]表示i出现的次数
                for (int j = 0; j < n; j++)
                    if (i >> j & 1)
                        freq[nums[j]]++;//统计当前方案中所有的数
                
                bool flag = true;
                for (int i = 0; i <= 16; i++) {
                    if (freq[i] > 1) {//当前方案选择的数有重复
                        flag = false;
                        break;
                    }
                }

                if (flag) {//计算不相容性
                    int minv = INT_MAX, maxv = INT_MIN;
                    for (int i = 1; i <= 16; i++)
                        if (freq[i]) minv = min(minv, i), maxv = max(maxv, i);
                    g[i] = maxv - minv;
                }
            }
        }

        f[0] = 0;
        for (int i = 1; i < 1 << n; i++) {
            if (__builtin_popcount(i) % (n / k) == 0) {//优化，只有i是合法方案才枚举子集
                for (int j = i; j; j = j - 1 & i) {//枚举i的所有子集
                    if (g[j] != -1)
                        f[i] = min(f[i], f[i - j] + g[j]);
                }
            }
        }
        int res = f[(1 << n) - 1];
        if (res == INF) return -1;
        else return res;
    }
};
```

