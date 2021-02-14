//理解题意，存储每个字符在每个字符串中出现的次数，时间复杂度O(n)，n为字符数，空间复杂度O(A.size()*26)
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int st[105][30];
        memset(st, 0, sizeof st);
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                st[i][A[i][j]-'a']++;
            }
        }
        
        vector<string> res;
        if (A.size() == 0) return res;
        for (int i = 0; i < 26; i++) {
            int cnt = INT_MAX;
            for (int j = 0; j < A.size(); j++) {
                cnt = min(cnt, st[j][i]);
            }
            while (cnt--) res.push_back(string(1, 'a'+i));
        }
        return res;
    }
};