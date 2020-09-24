# [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)

给定一个字符串，请你找出其中不含有重复字符的**最长子串**的长度。



**示例 1:**

**输入:** "abcabcbb"
**输出:** 3 
**解释:** 因为无重复字符的最长子串是 "abc"，所以其长度为 3。



**示例 2:**

**输入:** "bbbbb"
**输出:** 1
**解释:** 因为无重复字符的最长子串是 "b"，所以其长度为 1。



**示例 3:**

**输入:** "pwwkew"
**输出:** 3
**解释:** 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。



## 思路

**方法1**：暴力做法，枚举`i`从`0`到`len(s)`，`j`从`i+1`到`len(S)`，获取子串substr为`s[i, j-1]`，检测`s[j]`是否在`substr`中，在的话说明重复，不在的话更新最大不重复子串的长度。时间复杂度为$O(n^2)$

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 1;
        int len = s.size();
        if (len == 0) return 0;
        for (int i = 0; i < len; ++i) {
            for (int j = i+1; j < len; ++j) {
                string substr = s.substr(i, j-i);
                if (substr.find(s[j]) != string::npos) break;
                if (substr.find(s[j]) == string::npos && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    //cout << i << j << endl;
                }
            }
        }
        return maxLen;
    }
};
```



**方法2**：**双指针**算法。双指针算法的关键是找到**某种单调性**，从而降低时间复杂度，一般能减少一层循环。首先考虑如何找到单调性。假设我们已经寻找到`s[l, r]`之间的子串不存在重复字符，那么我们假设此时`r`向后移动一位，这使得`s[r+1]`加入该子串，如果`s[r+1]`加入后该子串（`s[l, r+1]`）仍然不存在重复字符，那么`l`不移动，如果`s[r+1]`加入该子串后，使得`s[l, r+1]`之间存在重复字符，那么重复字符一定是`s[r+1]`，这时我们将`l`向右移动，直到`s[l, r+1]`之间无重复字符。这里的单调性为：**当`r`往右移动时，`l`要么不移动，要么往右移动**，所以我们只需要枚举`r`即可，时间复杂度降为$O(n)$。判断一个子串中是否包含重复字符需要使用哈希表，**哈希表**的`key`为子串的各个字符，`value`为该字符在子串中出现的次数。

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> hash;
		//双指针算法：[l, r]表示无重复子串的区间，单调性为当r向后移动时，l一定不动或者向后移动
        for (int l = 0, r = 0; r < s.size(); r++) {
            hash[s[r]]++;
            if (hash[s[r]] > 1) {//s[r]在[l, r]中不止一个，一定是s[r]在该区间内重复
                while (hash[s[r]] > 1) {
                    hash[s[l]]--;//区间内字符s[l]减少
                    l++;		 //l往后移动
                }
            }
            res = max(res, r - l + 1);//更新答案
        }
        return res;
    }
};
```

