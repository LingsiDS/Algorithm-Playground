//区间贪心模板题，按照区间左端点排序，时间复杂度O(nlogn)，空间复杂度O(logn)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0) return res;

        sort(intervals.begin(), intervals.end());//按照左端点排序，vector对象支持比较，按照vector元素内的顺序排序
        
        int st = intervals[0][0], ed = intervals[0][1];//分别保存当前区间的左右端点
        for (int i = 1; i < intervals.size(); i++) {
            int s = intervals[i][0], d = intervals[i][1];
            if (s <= ed) {//区间重叠
                ed = max(ed, d);//更新当前区间右端点
            }
            else {//没有重叠
                res.push_back({st, ed});//记录当前区间
                st = s, ed = d;//更新当前区间
            }
        }
        res.push_back({st, ed});
        return res;
    }
};