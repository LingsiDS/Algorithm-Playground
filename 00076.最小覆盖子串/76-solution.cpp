//滑动窗口算法，时间复杂度O(n)，空间复杂度O(m)，m为字符串t的长度

//定义两个哈希表，第一个哈希表pattern存储字符串t中所有元素出现的次数（某些元素可能会出现多次）
//第二个哈希表window记录滑动窗口[st, ed]中所有在t中的字符出现的次数。
//遍历ed，扩大滑动窗口，如果s[ed]出现在t中，则window[s[ed]]++，表示该字符在滑动窗口中出现的
//次数增加，如果该字符是“有用的”len++，然后考虑窗口新增字符后，能否缩小窗口，如果开头元素没有
//出现在t中，或者开头元素出现在窗口的次数比在t中出现的次数还要多时，将窗口缩小st++，如果“有用”
//元素个数刚好等于t的大小，说明找到了t中的所有字符串，记录结果，最后取长度最小的字符串即可。
class Solution {
public:
    string minWindow(string s, string t) {//注意t中可能有多个重复元素
        
        unordered_map<char, int> window, pattern;
        for (auto c: t) {
            window[c] = 0; //记录滑动窗口中字符出现的次数
            pattern[c]++;  //记录t中每个字符的出现次数
        }

        string res;
        int len = 0, st = 0, ed = 0;
        while (ed < s.size()) {
            if (pattern.count(s[ed])) {//该字符出现在字符串t中
                window[s[ed]]++;//字符出现次数加一
                if (window[s[ed]] <= pattern[s[ed]]) len++;//找到“有用”的字符，有用字符长度len++
                while (pattern.count(s[st]) == 0 || window[s[st]] > pattern[s[st]]) {//考虑能否缩小滑动窗口
                    if (pattern.count(s[st]) != 0 && window[s[st]] > pattern[s[st]]) {//注意，要先试用count判断是否存在哈希表中，否则不再哈希表中的元素会被插入到哈希表中
                        window[s[st]]--;   //出现次数减少
                    }
                    st++;//缩小窗口
                }
                //len = t.size()说明已经找到t中所有字符
                if (len == t.size() && (res.empty() || ed-st+1 < res.size())) {
                    res = s.substr(st, ed-st+1);
                } 
            }
            ed++;
        }
        return res;
    }
};