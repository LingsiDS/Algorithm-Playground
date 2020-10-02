//模拟题
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        while (--n) res = getNext(res); 
        return res;
    }

    //得到s的下一个“外观数列”
    string getNext(string s) {
        int cnt = 1;
        string res;
        int idx = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) cnt++;
            else {
                res += to_string(cnt) + s[i - 1];
                cnt = 1;
            }
        }
        if (cnt) {
            res += to_string(cnt) + s[s.size() - 1];
            cnt = 1;
        }
        return res;
    }
};