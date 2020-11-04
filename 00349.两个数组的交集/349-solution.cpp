//时间复杂度O(n + m)，空间复杂度O(n + m)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash, hash2;
        for (auto a: nums1)//hash存储nums1里的元素
            hash.insert(a);
        
        vector<int> res;
        for (auto a: nums2)
            if (!hash2.count(a) && hash.count(a)) {//最后结果每个元素只能出现一次，hash2用来判断重复
                res.push_back(a);
                hash2.insert(a);
            }
        return res;
    }
};