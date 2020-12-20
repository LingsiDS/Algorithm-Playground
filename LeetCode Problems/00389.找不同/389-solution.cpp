//哈希表，时间复杂度O(n),空间复杂度O(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hash;

        for (auto c: s) hash[c]++;

        for (auto c: t) {
            hash[c]--;
            if (hash[c] == -1) return c;
        }
        return ' ';
    }
};

//位运算，时间复杂度O(n), 空间O(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (auto c: s) res ^= c;
        for (auto c: t) res ^= c;
        return res;
    }
};