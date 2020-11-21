//自己的直观思路，类似计数排序
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st(arr2.begin(), arr2.end());//st记录arr2中的所有元素，时间复杂度O(n)
        unordered_map<int, int> hash;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto a: arr1) {//时间复杂度O(m)
            if (st.count(a) == 0) {//不再arr2中的元素加入堆中
                pq.push(a);
            }
            else hash[a]++;//否则用哈希表将元素出现的次数记录下来
        }

        int idx = 0;
        for (auto a: arr2) {//顺序遍历arr2，对出现在arr2中的每个元素，找到该元素在arr1中出现的次数hash[a]，插入hash[a]个a元素，时间复杂度O(n)
            while (hash[a]--)
                arr1[idx++] = a;
        }

        while (pq.size()) {//对于不在arr2的元素，从堆中弹出插入数组末尾，最坏O(mlogm)
            arr1[idx++] = pq.top();
            pq.pop();
        }
        return arr1;
    }
};

//自定义排序规则
//遍历arr2，对于在arr2中出现的元素a，rank[a]记录该元素在arr2中的位置，排序时
//如果两个元素都在arr2中出现，则按照两个元素在arr2中的相对位置排序，
//如果有一个元素未出现在arr2中，则在arr2中的元素排在前面
//最后如果两个元素都不再arr2中，则按元素本身的大小排序
//时间复杂度O(nlogn)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> rank;
        for (int i = 0; i < arr2.size(); i++) {
            rank[arr2[i]] = i;
        }

        sort(arr1.begin(), arr1.end(), [&](int x, int y) {
            if (rank.count(x)) {
                return rank.count(y) ? rank[x] < rank[y] : true;
            }
            else return rank.count(y) ? false : x < y;
        });
        return arr1;
    }
};