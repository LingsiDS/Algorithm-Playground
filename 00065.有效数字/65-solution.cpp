//主要是总结非法字符的规则
//1 对于首尾有空格的情况，首先先把空格去掉，中间不能有空格
//2 对于+ - 号只能出现在开头，或者e的后面，并且正负号只能出现一次，同时不能只有符号
//3 对于e，不能出现在开头和结尾，不能出现多次
//4 对于.  不能出现多次，不能出现在e的后面，'.'后不能直接接e
//时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    bool isNumber(string s) {
        int l = 0, r = s.size()-1;
        //去掉多余空格
        while (s[l] == ' ') l++;
        while (s[r] == ' ') r--;
        if (l > r) return false;

        s = s.substr(l, r - l + 1);
        if (s[0] == '+' || s[0] == '-') s = s.substr(1);//这里判断正负号只能出现在开头
        if (s.size() == 0) return false;//只有符号'+'
        if (s[0] == 'e' || s[0] == 'E') return false;//'exxx'，e开头，错误
        if (s[0] == '.' && (s.size() <= 1 || s[1] == 'e' || s[1] == 'E')) return false;//'.e'  '.'  '.E'，  .后直接接e错误

        int dot = 0, e = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                if (dot > 0) return false;//'.xxx.'，出现多个'.'
                if (e > 0) return false;//'exxx.'  '.'出现在e后面
                dot++;
            }
            else if (s[i] == 'e' || s[i] == 'E'){
                if (i == s.size() - 1) return false;//不能结尾
                if (i == 0) return false;//不能开头
                if (e > 0) return false;//不能同时出现多个e
                if (s[i + 1] == '+' || s[i + 1] == '-') {
                    if (i + 2 == s.size()) return false;//'e+/-'并且后面没数了
                    else if (!isdigit(s[i + 2])) return false;//'e+/-'并且后面为非数字
                    i++;//跳过符号位
                }
                e++;
            }else if (s[i] < '0' || s[i] > '9') return false;//不是数字非法，空格，加减（出现在e后面跳过）不能出现在中间
        }
        return true;
    }
};