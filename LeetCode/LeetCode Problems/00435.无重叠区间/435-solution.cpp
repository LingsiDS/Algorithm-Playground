/*
贪心算法，时间复杂度O(nlogn)，空间复杂度O(logn)

区间问题的经典例题，首先我们确定应该对所有区间按照左端点或者右端点排序，但是按哪个端点需要分析
假设我们按区间右端点排序，并且我们考虑两个区间的右端点pre和cur，pre < cur，并且这两个区间有交集
此时我们应该选择区间pre。因为为了避免和后序区间产生重叠，那么选择的区间应该尽早结束，这样就得到了
贪心策略，将所有区间按照右端点排序，然后遍历所有区间，考虑两个相邻的区间pre和cur，如果cur和pre重叠，
那么删除区间cur，继续考虑下一个区间，否则将区间pre替换为cur
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        int res = 0;
        int ed = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < ed) {
                res++;
            }else {
                ed = intervals[i][1];
            }
        }
        return res;
    }
};