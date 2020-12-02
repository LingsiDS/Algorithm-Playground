//贪心算法，时间复杂度O(nlogC), 空间复杂度为O(C), C为小写字符集，

//为了使最后的字符串中相邻字符不重复，我们应该尽可能先使用出现的次数较多的字符去构造解，
//如果此时构造的解的末尾恰好是出现次数最多的字符，则会出现重复，这时
//应该使用出现次数为第二多的字符，使用这样的方法去构造的解相邻字符一定不会重复，最后如果
//没有其他字符，并且还存在冲突的情况，则不可能构造出相邻字符为不同的字符串，为了高效获得
//出现次数最多的字符，可以使用堆，将｛出现次数，字符｝作为一个二元组存入堆中

class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        vector<int> cnt(26, 0);//统计所有字符出现的次数
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> pq;//大顶堆
        for (auto c: S) {//统计每个字符出现的次数
            cnt[c - 'a']++;
        }
        
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i])
                pq.push({cnt[i], 'a' + i});//将每个字符出现的次数，以及该字符放入堆中
        }

        string res;
        while (pq.size()) {
            auto p = pq.top();//获取出现次数最多的字符
            pq.pop();
            if (res.empty() || res[res.size() - 1] != p.second) {//如果出现次数最多的字符不和res末尾的字符冲突，则使用出现次数最多的字符
                res += p.second;//使用出现最多的字符
                if (p.first - 1 != 0)
                    pq.push({p.first - 1, p.second});//使用过一次之后，将该字符的次数减少1，如果该字符还有，则将其数量减一再放入堆中
            } else {//出现最多的字符和当前的res末尾的字符重复，这时候使用出现次数【次多】的字符
                if (pq.empty()) return "";
                auto t = pq.top();//使用出现次数【次多】的字符
                pq.pop();
                res += t.second;
                if (t.first - 1 != 0) 
                    pq.push({t.first - 1, t.second});//该字符使用过一次，数量减一
                pq.push(p);
            }
        }
        return res;
    }
};