//时间复杂度O(n*logn*logn)，排序时间O(n*logn)，排序中获得二进制位数需要logn
//空间复杂度O(logn)排序的代价
class Solution {
public:
    int mask = 0;

    int get_bit(int x) {
        int cnt = 0;
        while (x) {
            if (x & 1) cnt++;
            x = x >> 1;
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int a, int b) ->bool{
            int ta = get_bit(a), tb = get_bit(b);
            if (ta < tb) return true;
            else if (ta > tb) return false;
            else return a < b;
        });
        return arr;
    }
};