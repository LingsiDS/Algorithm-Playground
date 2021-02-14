//先试用哈希表存储数组中每个字符出现的次数，然后遍历哈希表，判断所有出现的次数是否有相同的，有return false否则return true
//时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hash;
        for (auto c: arr) {
            hash[c]++;
        }
        set<int> s;
        for (auto it = hash.begin(); it != hash.end(); it++) {
            if (s.count(it->second)) return false;
            s.insert(it->second);
        }
        return true;
    }
};