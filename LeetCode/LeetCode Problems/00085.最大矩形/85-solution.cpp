//单调栈，枚举所有行，该行以及该行之上的所有连续的1构成一个柱状图，利用84题的解法解决即可，时间复杂度O(n^2)，空间复杂度O(n^2)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {//84题的解法
        int n = heights.size();
        if (n == 0) return 0;
        vector<int> l, r(n, -1);
        stack<int> stk, stk2;//单调递增栈，找到第一个比heights[i]小的下标
        for (int i = 0; i < heights.size(); i++) {//在i的左边找第一个比heights[i]小的下标
            if (stk.empty()) {
                l.push_back(-1);//所有元素都比heights[i]大
                stk.push(i);
            }
            else {
                while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();//弹出比heights[i]大的元素
                if (stk.empty()) l.push_back(-1);
                else l.push_back(stk.top());
                stk.push(i);
            }
        }

        for (int i = heights.size()-1; i >= 0; i--) {//在i的右边找第一个比heights[i]小的下标
            if (stk2.empty()) {
                r[i] = n;//所有元素都比heights[i]大
                stk2.push(i);
            }
            else {
                while (!stk2.empty() && heights[stk2.top()] >= heights[i]) stk2.pop();//弹出比heights[i]大的元素
                if (stk2.empty()) r[i] = n;
                else r[i] = stk2.top();
                stk2.push(i);
            }
        }

        int res = 0;
        for (int i = 0; i < heights.size(); i++) {//枚举所有高度，计算以heights[i]为高度的矩形的面积
            res = max(res, heights[i] * (r[i] - l[i] - 1));
        }

        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));//f[i][j]表示f[i][j]以及f[i][j]之上一共有多少个连续的1
        int res = 0;
        for (int i = 0; i < m; i++) {//枚举基准线（柱状图的底）
            for (int j = 0; j < n; j++) {
                if (i == 0 && matrix[i][j] == '1') f[i][j] = 1;
                else if (i && matrix[i][j] == '1') f[i][j] = 1 + f[i - 1][j];
                else f[i][j] = 0;
            }
            res = max(res, largestRectangleArea(f[i]));//调用第84题的解法
        }
        return res;
    }
};