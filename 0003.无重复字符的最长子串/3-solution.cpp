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