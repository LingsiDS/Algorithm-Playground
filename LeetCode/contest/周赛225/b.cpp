class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> va(26, 0);
        auto vb = va, sum = va;
        
        for (auto &t: a) {
            va[t - 'a']++;
            sum[t - 'a']++;
        }
        
        for (auto &t: b) {
            vb[t - 'a']++;
            sum[t - 'a']++;
        }
        
        int res = a.size() + b.size() - *max_element(sum.begin(), sum.end());//将两个字符串转化为同一字母
        
        
        vector<int> sa(27, 0);
        auto sb = sa;
        
        for (int i = 1; i <= 26; i++) sa[i] = sa[i - 1] + va[i - 1];
        for (int i = 1; i <= 26; i++) sb[i] = sb[i - 1] + vb[i - 1];
        
        for (int i = 1; i <= 25; i++) {
            int la = sa[i], ra = sa[26] - sa[i];
            int lb = sb[i], rb = sb[26] - sb[i];
            res = min(res, ra + lb);
            res = min(res, la + rb);
        }
        return res;
    }
};
