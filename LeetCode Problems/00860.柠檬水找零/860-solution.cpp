//模拟+贪心，在要找15块，钱的时候，优先考虑用10块钱+5块钱的方案，没有10块钱再用5+5+5因为5更通用
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0, t = 0, res = 0;//f 5块钱， t10块钱，res总价钱
        for (auto a: bills) {
            int left = a - 5;//要找的零钱数
            if (res < left) return false;
            while (left) {
                if (left >= 10 && t) left -= 10, t--;//优先找10块钱
                while (left >= 5 && f) left -= 5, f--;//还没找完，再用5块钱
                if (left) return false;
            }
            if (a == 5) f++;
            if (a == 10) t++;
            res += 5;
        }
        return true;
    }
};