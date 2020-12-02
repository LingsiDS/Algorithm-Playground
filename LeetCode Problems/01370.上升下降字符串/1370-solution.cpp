//朴素思想，模拟，时间复杂度O(n^2)，n为字符串s的长度，空间复杂度O(1)
class Solution {
public:
    string sortString(string s) {
        sort(s.begin(), s.end());

        string res;
        
        vector<bool> st(s.size(), false);
        int cnt = 0;
        while (cnt < s.size()) {
            char pre = ' ';
            for (int i = 0; i < s.size(); i++) {
                if (!st[i] && s[i] > pre) {
                    pre = s[i];
                    res += s[i];
                    st[i] = true;
                    cnt++;
                }
            }

            pre = 'z'+1;
            for (int i = s.size() - 1; i >= 0; i--) {
                if (!st[i] && s[i] < pre) {
                    pre = s[i];
                    res += s[i];
                    st[i] = true;
                    cnt++;
                }
            }
        }
        return res;
    }
};

//桶计数的思想，最坏情况下，时间复杂度O(26*n)，n为s的长度，空间复杂度O(26)-->O(1)
class Solution {
public:
    string sortString(string s) {
        string res;
        vector<int> bucket(26, 0);
        for (auto &c: s) bucket[c - 'a']++;

        while (res.size() < s.size()) {
            for (int i = 0; i < 26; i++) {
                if (bucket[i]) {
                    res += ('a' + i);
                    bucket[i]--;
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (bucket[i]) {
                    res += ('a' + i);
                    bucket[i]--;
                }
            }
        }
        return res;
    }
};