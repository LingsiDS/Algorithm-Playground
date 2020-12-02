//直观思路，贪心，模拟，要让删除的元素更小，则应该删除高位的较大的元素
//从高位遍历到低位，如果第i位大于第i+1位，则删除第i位，同时i指针后移一位，这样删完一定变小，同时从高位删除保证了一定是最小
//删除一个string某个位置上的元素，该位置后的元素会引起移动，最坏情况下时间复杂度为O(n^2)
class Solution {
public:
    string removeKdigits(string num, int k) {
        for (int i = 0; i < num.size() && k; i++) {
            if (i + 1 < num.size() && num[i + 1] < num[i]) {
                num.erase(i, 1); 
                k--;
                if (i - 1 >= 0) i-= 2; //删除完i指针后移一位，-2是因为for循环i还会+1
                else i--;//删除的是第1位
            }
        }
        while (num.size() && k) {//如果是升序排列，则后面的数字更大，从后往前删除
            num.pop_back();
            k--;
        }
        while (num[0] == '0') num.erase(0, 1);//删除前导0
        if (num == "") num = "0";
        return num;
    }
};


//单调栈，一个元素保留下来的条件是其高位的元素都小于等于该元素，否则删除高位比它大的元素，将它作为高位会获得更小的元素
//时间复杂度O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        int remain = num.size() - k;
        for (int i = 0; i < num.size(); i++) {
            while (stk.size() && stk[stk.size() - 1] > num[i] && k) {
                k--;
                stk.pop_back();
            }
            stk.push_back(num[i]);
        }

        string res;
        for (int i = 0; i < stk.size(); i++) {
            if (remain) {
                if (res.empty() && stk[i] == '0') continue;
                res.push_back(stk[i]);
                remain--;
            } else break;
        }
        return res.size() ? res : "0";
    }
};