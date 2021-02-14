# LeetCode-Solutions
个人LeetCode笔记



## 题目整理

### **记忆化递归**

- [343.整数拆分](https://leetcode-cn.com/problems/integer-break/)，[剑指offer-14.剪绳子](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/)（数学）

### 单调栈

- [84.柱状图中最大的矩形面积](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)
- [85.最大矩形](https://leetcode-cn.com/problems/maximal-rectangle/)
- [402.移掉k位数字](https://leetcode-cn.com/problems/remove-k-digits/)
- [1081. 不同字符的最小子序列](https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters/) （思路同上题）
- [316. 去除重复字母](https://leetcode-cn.com/problems/remove-duplicate-letters/)

### 贪心

贪心很多时候是从直观的思路出发，猜测一个解法，然后对样例使用这种方法，如果可行，可以先尝试实现。贪心算法的正确性证明往往比较困难。

贪心往往与最大最小相关，所以可能会结合其他算法或者数据结构一起使用，比如结合排序，堆等

- [452.用最少数量的箭引爆气球](https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/)
- [976. 三角形的最大周长](https://leetcode-cn.com/problems/largest-perimeter-triangle/) （贪心、排序、数学）
- [767. 重构字符串](https://leetcode-cn.com/problems/reorganize-string/) （贪心 、堆）
- [659. 分割数组为连续子序列](https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/) (第一次没做出来)
- [621. 任务调度器](https://leetcode-cn.com/problems/task-scheduler/) （还有一种数学解法）
- [376. 摆动序列](https://leetcode-cn.com/problems/wiggle-subsequence/)
- [714. 买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

### 分治

- [493. 翻转对](https://leetcode-cn.com/problems/reverse-pairs/)（分治+双指针）
- [290. 单词规律](https://leetcode-cn.com/problems/word-pattern/)

###  哈希表

- [454. 四数相加 II](https://leetcode-cn.com/problems/4sum-ii/)

### 桶排序/基数排序

- [164. 最大间距](https://leetcode-cn.com/problems/maximum-gap/)

### 搜索

- [842. 将数组拆分成斐波那契序列](https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence/)

### 数学

[204. 计数质数](https://leetcode-cn.com/problems/count-primes/)

[263. 丑数](https://leetcode-cn.com/problems/ugly-number/)

### 队列

[649. Dota2 参议院](https://leetcode-cn.com/problems/dota2-senate/)

### 动态规划

[174. 地下城游戏](https://leetcode-cn.com/problems/dungeon-game/) （状态定义可以依据问题考虑，最简单的想法，问什么定义什么）

### 树

[235. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

[236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

### 设计题

设计题多考察数据结构的使用，使用已有的数据结构，设计支持其他操作的高效数据结构。

[295. 数据流的中位数](https://leetcode-cn.com/problems/find-median-from-data-stream/)

### 并查集

[990. 等式方程的可满足性](https://leetcode-cn.com/problems/satisfiability-of-equality-equations/)

[1631. 最小体力消耗路径](https://leetcode-cn.com/problems/path-with-minimum-effort/)（经典题，连通性，最短路，二分）

[778. 水位上升的泳池中游泳](https://leetcode-cn.com/problems/swim-in-rising-water/)（和上题一样）

[721. 账户合并](https://leetcode-cn.com/problems/accounts-merge/)

### 双指针/滑动窗口

[424. 替换后的最长重复字符](https://leetcode-cn.com/problems/longest-repeating-character-replacement/)





## 系列题

### 买卖股票系列

[121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)（一次遍历/简单dp）

[122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)（贪心/dp）

[123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)（前后缀分解/dp）

[188. 买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/) （状态机DP）

[714. 买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) （贪心/dp）
