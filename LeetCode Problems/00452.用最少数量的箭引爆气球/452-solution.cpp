//贪心，时间复杂度O(nlogn)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty() || points[0].empty()) return 0;
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {//按区间右端点排序
            return a[1] < b[1];
        });
        int res = 0;
        int p = points[0][1];
        res = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= p) {
                continue;
            }
            else {
                p = points[i][1];//每次选择区间的右端点
                res++;
            }
        }
        return res;
    }
};