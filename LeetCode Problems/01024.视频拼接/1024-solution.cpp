//1024快乐（2020年10月24日 10:58:41）：）XD
//贪心题，时间复杂度O(nlogn)n为区间的数目，空间复杂度O(logn)排序代价，基本思路就是选能覆盖最远的区间，这样区间数目最小
class Solution {
public:
    int videoStitching(vector<vector<int>>& a, int T) {
        if (a.empty() || a[0].empty()) return -1;
        sort(a.begin(), a.end(), [](vector<int>& a, vector<int>&b) {//按区间左端点升序排序
            if (a[0] < b[0]) return true;
            else if (a[0] == b[0]) return a[1] > b[1];//对于区间左端点相同的区间，按照右端点降序排序，这样第一个区间一定是最长的
            else return false;
        });

        int res = 1, st = a[0][0], ed = a[0][1], maxl = a[0][1], idx = 0;//选取第一个区间，第一个区间一定是最长的
        
        if (st > 0) return -1;//如果不能覆盖起始点之前的区间，返回-1
        if (maxl >= T) return res;//如果第一个区间就能覆盖整个区间，返回res
        for (int i = 1; i < a.size(); i++) {//从第一个区间开始
            if (a[i][0] <= ed && a[i][1] > maxl) {//找能连接上，且能覆盖的最远的区域
                maxl = a[i][1];
                idx = i;
                if (maxl >= T) return res+1;
            }
            else if (a[i][0] > ed) {
                if (a[i][0] > maxl) return -1;//不能无缝连接
                else {
                    st = a[idx][0], ed = a[idx][1];//把找到的能覆盖最远的区间作为当前区间
                    i--;//重新计算区间i
                    res++;
                }
            }
        }
        if (maxl < T) return -1;//找完仍然不能完整覆盖T
        return res;
    }
};