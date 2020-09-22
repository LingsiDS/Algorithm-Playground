typedef long long ll;
class Solution {
public:
    int myAtoi(string str) {
        int idx = 0;
        ll res = 0;
        //查找第一个非空字符
        while (str[idx] && str[idx] == ' ') idx++;
        
        //第一个非空字符为非法字符
        if (!isdigit(str[idx]) && str[idx] != '-' && str[idx] != '+') return 0;
        
        //第一个非空字符为'-'
        if (str[idx] == '-') {
            if (idx + 1 < str.size() && isdigit(str[idx+1])) {//转化为负数
                idx++;
                while (idx < str.size() && isdigit(str[idx])) {
                    res = res * 10 + str[idx] - '0';
                    idx++;
                    //将字符转化为数字的过程中可能会超过long long的表示范围
                    if (res > INT_MAX) {
                        res = INT_MIN;
                        break;
                    }
                }
                res *= -1;
            }
            return res;
        }

        //第一个非空字符为'+'
        if (str[idx] == '+') {
            if (idx + 1 < str.size() && isdigit(str[idx + 1])) {
                idx++;
                while (idx < str.size() && isdigit(str[idx])) {
                    res = res * 10 + str[idx] - '0';
                    idx++;
                    if (res > INT_MAX) {
                        res = INT_MAX;
                        break;
                    }
                }
            }
            return res;
        }

        //第一个非空字符为数字，转化为正数
        while (idx < str.size() && isdigit(str[idx])) {
            res = res * 10 + str[idx] - '0';
            idx++;
            if (res > INT_MAX) {
                res = INT_MAX;
                break;
            }
        }
        return res;
    }
};