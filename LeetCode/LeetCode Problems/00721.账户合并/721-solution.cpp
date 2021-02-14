/*
并查集，将每个人所有的email加入一个集合中，如果多个人有同样的email，则将这两个人的email集合合并
由于并查集比较适于处理整数而不是字符串，故这里需要使用一系列辅助存储结构记录需要的信息

时间复杂度O(nlogn)，n为所有邮件的数量
*/
class Solution {
public:
    unordered_map<string, int> strToIdx;//email到整数的映射
    vector<string> idxToStr;            //整数到email的映射
    unordered_map<int, string> name;    //name[i]存储的是用户i的名字
    vector<int> p;  //并查集数组

    int find(int x) {//并查集的查找
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    int getIdx(string s) {//从字符串得到下表
        if (strToIdx.count(s)) return strToIdx[s];
        strToIdx[s] = idxToStr.size();
        idxToStr.push_back(s);
        return strToIdx[s];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        p.resize(10010, 0);

        for (int i = 0; i < p.size(); i++) p[i] = i;//初始化并查集

        for (auto &vec: accounts) {
            if (vec.size() < 1) continue;
            auto root = find(getIdx(vec[1]));
            name[root] = vec[0];//name 通过并查集的代表元素获取组名
            for (int i = 2; i < vec.size(); i++) {
                auto idx = getIdx(vec[i]);
                p[find(idx)] = root;//合并
            }
        }

        vector<vector<string>> res;
        unordered_map<int, int> resIdx;//并查集代表根元素在res的下标
        for (int i = 0; i < strToIdx.size(); i++) {//将同一个人的所有邮箱合并
            string curMail = idxToStr[i];
            string rootName = name[find(i)];
            int root = find(i);
            if (resIdx.count(root)) {
                res[resIdx[root]].push_back(curMail);    
            } else {
                resIdx[root] = res.size();
                res.push_back({rootName, curMail});
            }
        }
        for (auto &vec: res) {//对返回结果排序
            sort(vec.begin() + 1, vec.end());
        }
        return res;
    }
};