//简单哈希，时间复杂度O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> hash;
        for (auto c: t) hash[c]++;//记录单词出现次数

        for (auto c: s) {
            if (!hash[c]) return false;//t中没有该字符，或者该字符“用完”，return false;
            hash[c]--;
        }
        return true;
    }
};