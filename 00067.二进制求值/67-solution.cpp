//O(max(n, m))
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size() - 1, m = b.size() - 1;
        string res;
        if (n == -1 && m == -1) {
            res.push_back('0');
            return res;
        } 
        int c = 0;
        while (n >= 0 && m >= 0) {
            int x = a[n] - '0', y = b[m] - '0';
            int t = (x + y + c) % 2;
            c = (x + y + c) / 2;
            res.push_back(t+'0');
            n--;
            m--;
        }

        while (n >= 0) {
            int x = a[n] - '0';
            int t = (x + c) % 2;
            c = (x + c) / 2;
            res.push_back(t+'0');
            n--;
        }

        while (m >= 0) {
            int x = b[m] - '0';
            int t = (x + c) % 2;
            c = (x + c) / 2;
            res.push_back(t+'0');
            m--;
        }
        if (c) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};