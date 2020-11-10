//时间复杂度O(nlogn)，空间复杂度O(n)存储下标
//主要的思路是先对区间的左端点排序，然后遍历区间，对当前区间，其后区间左端点已经被排序过
//对当前区间之后的区间进行二分查找，查找后序区间的左端点大于当前区间右端点的第一个区间即为答案
//共n个区间，对后面n-1个区间二分查找需要O(nlogn)
struct node{
    int l, r, idx;
};
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> res(n, 0);
        vector<node> s;
        for (int i = 0; i < intervals.size(); i++) {
            s.push_back({intervals[i][0], intervals[i][1], i});
        }

        //按区间左端点排序，区间左端点相等时按idx排
        sort(s.begin(), s.end(), [](node &a, node &b) {
            if (a.l < b.l) return true;
            else if (a.l == b.l) return a.idx < b.idx;
            else return false;
        });
        
        int k = 0;
        for (auto a: s) {
            int l = ++k, r = n - 1;
            while (l < r) {//二分查找后序区间中终点大于当前区间的起点的点
                int mid = (l + r) / 2;
                if (s[mid].l >= a.r) r = mid;
                else l = mid + 1;
            }
            if (l == r && s[r].l >= a.r) res[a.idx] = s[l].idx;
            else res[a.idx] = -1;
        }
        return res;
    }
};