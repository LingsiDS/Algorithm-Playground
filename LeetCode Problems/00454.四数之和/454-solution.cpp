//哈希表，时间复杂度O(n^2)，空间复杂度O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hash;
        for (auto a: A) {
            for (auto b: B)
                hash[a + b]++;
        }

        int res = 0;
        for (auto c: C)
            for (auto d: D)
                res += hash[-(c + d)];
        
        return res;
    }
};