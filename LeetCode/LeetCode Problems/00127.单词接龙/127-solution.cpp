//BFS，将字符串入队，每次取队头的字符串，同时枚举改变该字符串的每一个位置，如果改变后的单词在单词列表中
//则将其入队，如果改变后的单词已经和endWord相等，直接返回，如果从当前字符串可以到达s，则只需要一个字符串即可，
//同时为了防止两个单词循环入队，单词s入队后，在哈希表中删除s
//时间复杂度O(m*n*c)，m为字符串的个数，n为字符串长度，c为小写字符集大小26，空间最坏O(m)
class Solution {
public:
    struct node {
        string s;
        int cnt;
    };

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int res = 1;
        queue<node> q;
        unordered_set<string> hash(wordList.begin(), wordList.end());
        if (beginWord == endWord) return 1;
        if (!hash.count(endWord)) return 0;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto p = q.front();
            string s = p.s;
            int cnt = p.cnt;

            q.pop();
            for (int i = 0; i < s.size(); i++) {
                char t = s[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (s[i] != c) {
                        s[i] = c;
                        if (hash.count(s)) {
                            //cout << s << endl;
                            if (s == endWord) return cnt + 1;
                            q.push({s, cnt + 1});
                            hash.erase(s);
                        }
                    }
                }
                s[i] = t;
            }
        }
        return 0;
    }
};


//思路和上面一样，判断重复节点方面不同，上面的方法是删除wordList里的字符串，这里是看当前节点最短路是否已经计算出来
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash(wordList.begin(), wordList.end());
        unordered_map<string, int> dist;

        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 1;

        while (!q.empty()) {
            auto s = q.front();
            q.pop();

            string t = s;
            for (int i = 0; i < s.size(); i++) {
                s = t;
                for (int c = 'a'; c <= 'z'; c++) {
                    if (c == s[i]) continue;
                    s[i] = c;
                    if (hash.count(s) && !dist.count(s)) {//从s出发的可行路径，并且该理解没有被计算过最短路
                        dist[s] = dist[t] + 1;
                        if (s == endWord) return dist[s];
                        q.push(s);
                    }
                }
            }
        }
        return 0;
    }
};