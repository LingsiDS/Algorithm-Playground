//动态规划：定义状态dp[i] = 1，表示从从s[1, i]能否划分为字典里出现过的单词
//枚举最后一个划分的字符s[k, i]，如果其在字典中，则dp[i] = dp[k-1]，即如果前k-1个单词也能划分，则加上
//这个单词也能划分，时间复杂度看上去是O(n^2)，实际上是O(n^3)，在哈希表中判断一个字符串在不在哈希表时间与字符串长度相关
//空间复杂度O(n)使用了哈希表
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, 0);//dp[i]表示从s[1, i]能否划分为字典里出现过的单词
        unordered_set<string> hash(wordDict.begin(), wordDict.end());

        s = " " + s;//方便边界判断
        dp[0] = true;
        for (int i = 1; i < s.size(); i++) {
            for (int k = i; k >= 1; k--) {//枚举完所有情况
                if (hash.count(s.substr(k, i - k + 1))) {
                    dp[i] = dp[i] | dp[k - 1];//使用或运算，保证只要有一个可能的划分即可
                }
            }
        }
        return dp[s.size() - 1];
    }
};