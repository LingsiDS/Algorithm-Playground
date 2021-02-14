//关键点：如果一个字符出现在某个片段中，则字符串S中该字符最后出现的位置也应该在同一个片段中
//所以首先记录字符串S中每个字符的起始位置和结束位置，该问题中字符都是小写字符，故最多26个
//得到所有字符的出现区间后，对该区间的起始位置排序，遍历每个区间，首先记录起始区间[st, ed]
//对每个遍历到的区间，如果当前区间在[st, ed]内，说明该字符应该在该片段内；如果当前区间与
//[st, ed]区间有交集，则说明我们的最小的结束位置ed需要更新；如果当前区间与区间[st, ed]完全没有
//交集，说明以前一个字符结尾得到一个最小的片段，记录长度，同时更新区间[st, ed]
//官方题解的思路描述，表达的非常清晰：上述做法使用贪心的思想寻找每个片段可能的最小结束下标，
//因此可以保证每个片段的长度一定是符合要求的最短长度，如果取更短的片段，则一定会出现同一个字母出现在多个片段中的情况。
//由于每次取的片段都是符合要求的最短的片段，因此得到的片段数也是最多的。
//时间复杂度O(n)，空间复杂度O(C)，其中C为字符串的大小
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<vector<int>> arr(26, vector<int>(2, -1));

        for (int i = 0; i < S.size(); i++) {//记录区间的起始和结束位置
            int idx = S[i] - 'a';
            if (arr[idx][0] == -1) arr[idx][0] = i;
            arr[idx][1] = max(arr[idx][1], i);
        }

        vector<vector<int>> vec;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i][0] != -1 ) {
                vec.push_back(arr[i]);
            }
        }

        sort(vec.begin(), vec.end());//排序复杂度最高为nlogn，但是n=26，只有26个字符集
        vector<int> res;
        if (!S.size()) return res;
        
        int st = vec[0][0], ed = vec[0][1];
        int len = ed - st + 1;
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i][0] < ed && vec[i][1] < ed) {//当前区间包含在[st, ed]之间
                continue;
            }
            else if (vec[i][0]  < ed && vec[i][1] > ed) {//区间增大
                len += vec[i][1] - ed;
                ed = vec[i][1];
            } 
            else if (vec[i][0] > ed) {//新区间
                res.push_back(len);
                st = vec[i][0];
                ed = vec[i][1];
                len = ed - st + 1;
            }
        }
        res.push_back(len);
        return res;
    }
};

//更简洁的版本，只记录每个字符的结束位置
//然后遍历字符串，对于字符串中的每个字符S[i]，如果i恰好为结束位置，则记录当前片段，否则更新当前片段的最小结束下标
//时间复杂度O(n)，空间复杂度O(C)，其中C为字符串的大小
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26] = {0};
        
        for (int i = 0; i < S.size(); i++) {
            int idx = S[i] - 'a';
            last[idx] = max(last[idx], i);
        }

        vector<int> res;
        int st = 0, ed = 0;
        for (int i = 0; i < S.size(); i++) {
            int idx = S[i] - 'a';
            ed = max(ed, last[idx]);//当前片段的结束下标一定不小于last[idx]
            if (ed == i) {//如果i恰好为结束位置，则记录该片段
                res.push_back(ed - st + 1);
                ed = st = i + 1;
            }
        }
        return res;
    }
};