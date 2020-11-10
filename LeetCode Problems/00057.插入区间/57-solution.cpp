//2020年11月4日 16:33:19重做
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int st = newInterval[0], ed = newInterval[1];
        int i = 0;
        int push = 0;//标记新区间是否已经插入
        for (; i < intervals.size(); i++) {
            if (st <= intervals[i][1] && ed >= intervals[i][0]) {//新区间和老区间有交集
                st = min(st, intervals[i][0]);
                ed = max(ed, intervals[i][1]);//更新区间大小
            } else if (!push && intervals[i][0] > ed) {//新区间与老区间没有交集了，插入新区建
                push = 1;
                res.push_back({st, ed});
                i--;//再次考虑老区间，将老区间插入res中
            }
            else {
                res.push_back(intervals[i]);//插入老区间
            }
        }
        if (!push) res.push_back({st, ed});//新区建还没插入，插入
        return res;
    }
};


//遍历区间插入，需要考虑的情况较多，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> res;
        int n = a.size();
        if (n == 0){
            res.push_back(b);
            return res;
        }

        //处理要插入的区间b在所有区间前面的情况
        if (b[0] < a[0][0]) {
            if (b[1] < a[0][0]) {//没有交集
                a.insert(a.begin(), b);
                return a;
            }
            else {//b[1] >= a[0][0]
                int st = b[0], ed = max(b[1], a[0][1]);
                int j = 1;
                while (j < a.size() && a[j][0] <= ed) {
                    ed = max(ed, a[j][1]);
                    j++;
                }
                res.push_back({st, ed});
                while (j < a.size()) res.push_back(a[j++]);
                return res;
            }
        }
        
        //b在所有区间后面
        if (b[0] > a[a.size()-1][1]) {
            a.push_back(b);
            return a;
        }

        //要插入的区间在a区间之后
        bool f = false;//f表示b区间是否已经使用过了
        for (int i = 0; i < n; i++) {
            if (b[0] <= a[i][1] && !f) {
                if (b[1] < a[i][0]) {//b与任何区间都没有交集
                    res.push_back(b);
                    res.push_back({a[i][0], a[i][1]});
                    f = 1;
                    continue;
                }
                //b与当前区间a[i][0], a[i][1]有交集，合并区间
                int st = min(a[i][0], b[0]), ed = max(a[i][1], b[1]);
                int j = i + 1;
                while (j < n && a[j][0] <= ed) {
                    ed = max(ed, a[j][1]);
                    j++;
                }
                f = 1;
                res.push_back({st, ed});
                i = j - 1;
            }else {
                res.push_back({a[i][0], a[i][1]});
            }
        }
        
        return res;
    }
};


//直接插入区间后排序，做法和合并区间一样，时间复杂度O(nlogn)，空间复杂度O(logn)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        a.push_back(b);
        vector<vector<int>> res;
        if (a.size() ==0) return res;
        sort(a.begin(), a.end());
        
        int st = a[0][0], ed = a[0][1];
        for (int i = 1; i < a.size(); i++) {
            if (a[i][0] <= ed) {
                ed = max(ed, a[i][1]);
            }
            else {
                res.push_back({st, ed});
                st = a[i][0];
                ed = a[i][1];
            }
        }
        res.push_back({st, ed});
        return res;
    }
};