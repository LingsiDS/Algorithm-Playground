class Solution {
public:
    int minimumBoxes(int n) {
        int sum = 0, k = 1;

        while (sum + (k + 1) * k / 2 <= n) {//考虑完整的阶梯形摆放
            sum += (k + 1) * k / 2;
            k++;
        }

        int res = k * (k - 1) / 2;//当前完美阶梯形状，最底层盒子的数量，
        
        k = 1;
        while (sum < n) {//不能凑足下一个阶梯形的部分继续摆放
            res++;//最底层每增加一个盒子
            sum += k;//可以在此基础上再放k个盒子，k从1开始递增
            k++;
        }
        return res;
    }
};
