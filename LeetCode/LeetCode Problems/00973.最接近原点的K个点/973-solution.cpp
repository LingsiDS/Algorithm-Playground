//使用大顶堆，保存距离为前k大的元素
//时间复杂度O(n*logK)，空间复杂度O(K)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;//大顶堆，默认按照pair的第1个元素排序

        for (int i = 0; i < points.size(); i++) {//时间复杂度O(n*logK)
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (q.empty()) q.push({dist, i});
            else if (!q.empty()) {
                if (q.size() < K) q.push({dist, i});
                else {
                    if (q.top().first > dist) {
                        q.pop();
                        q.push({dist, i});
                    }
                }
            }
        }

        vector<vector<int>> res;
        while (K--) {
            auto p = q.top();
            q.pop();
            res.push_back(points[p.second]);
        }

        return res;
    }
};

//快速排序的思想，时间复杂度期望为O(n)，空间复杂度为O(logn)
class Solution {
public:
    vector<vector<int>> res;
    int order;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        order = K;
        vector<pair<int, int>> dist;
        for (int i = 0; i < points.size(); i++) {//预处理出<距离，下标>的pair
            dist.push_back({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
        }
        quick_select(dist, 0, dist.size() - 1, K, points);
        return res;
    }

    void quick_select(vector<pair<int, int>> &p, int l, int r, int K, vector<vector<int>>& points) {
        if (l == r) {
            for (int i = 0; i < order; i++) {//记录前K个点作为答案
                res.push_back(points[p[i].second]);
            }
            return;
        }
        int x = p[(l + r) / 2].first;
        int i = l - 1, j = r + 1;
        while (i < j) {
            do i++; while (p[i].first < x);
            do j--; while (p[j].first > x);
            if (i < j) swap(p[i], p[j]);
        }//partition后，[l, j] 小于x，[j + 1, r] 大于x

        int left_num = j - l + 1;//左边元素的个数
        if (left_num >= K) 
            quick_select(p, l, j, K, points);
        else
            quick_select(p, j + 1, r, K - left_num, points);
    }
};