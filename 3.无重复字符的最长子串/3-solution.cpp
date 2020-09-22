class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> hash;
        //双指针算法：[j, i]表示无重复子串的区间，单调性为当i向后移动时，j一定不动或者向后移动
        for (int i = 0, j = 0; i < s.size(); i++) {
            hash[s[i]]++;
            if (hash[s[i]] > 1) {//s[i]在[j, i]中不止一个，一定是s[i]在该区间内重复
                while (hash[s[i]] > 1) {hash[s[j++]]--;}//j往后移动，同时该区间内字符s[j]减少
            }
            res = max(res, i - j + 1);//更新答案
        }
        return res;
    }
};