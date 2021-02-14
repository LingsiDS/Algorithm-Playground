//哈希表，维护映射关系，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> mp;
        unordered_set<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (st.count(t[i]) == 0 && mp.count(s[i]) == 0) {//两边都没有建立映射关系
                st.insert(t[i]);
                mp[s[i]] = t[i];
            } else {
                if (mp[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};