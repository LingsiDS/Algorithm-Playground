//排序+滑动窗口时间复杂度 O(nlogn),空间复杂度O(n),n为点的数量
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int org = 0;
        vector<double> ag;
        for (int i = 0; i < points.size(); i++) {
            if (location[0] == points[i][0] && location[1] == points[i][1])
                org++;//和原点相同的点,因为在任何角度都能看见,特殊处理
            else {
                ag.push_back(atan2(points[i][1] - location[1], points[i][0] - location[0]));//将所有点转换为与原点的角度
            }
        }
        int n = ag.size();
        for (int i = 0; i < n; i++) ag.push_back(ag[i] + 2 * M_PI);//将所有点加上2*M_PI复制一遍
        sort(ag.begin(), ag.end());//对所有角度进行排序

        int res = 0, l = 0;//ag[l],ag[r]分别指示当前视角的左右边界与原点的弧度
        double visiable = angle * M_PI / 180.0;//可视角度转化为可以看见的弧度
        for (int r = 0; r < ag.size(); r++) {//滑动窗口算法,每次更新右边界
            while (l < ag.size() && l < r && ag[r] - ag[l] > visiable) l++;//如果ag[r]-ag[l]超过了可视弧度,l++更新左端点
            res = max(res, r - l + 1);//记录最多可以看见的点
        }
        return res + org;
    }
};