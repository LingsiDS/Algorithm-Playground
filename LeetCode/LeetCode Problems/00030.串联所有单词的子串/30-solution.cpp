//int n = s.size(), m = words.size(), w = words[0].size();
//这题利用words里字符串长度都是w，在s中找字串时，将查找过程分为w组，
//每组的下标对m取余分别为0, 1, 2, ..., m - 1, 在每一组中的遍历中，只考虑长度固定为w的子串，
//遍历每一组时，维护一个长度为m的滑动窗口，将滑动窗口中的所有子串存储到哈希表中，
//再判断滑动窗口中的所有子串是否和words中的子串相等
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.size() == 0) return res;
        int n = s.size(), m = words.size(), w = words[0].size();

        unordered_map<string, int> hash;//key为字符串，val为字符串出现的次数
        for (auto &ws: words) hash[ws]++;//

        //将s分为w组，每组的下标起始为0 ~ w,以下总的时间复杂度为O(w * n)
        for (int i = 0; i < w; i++) {//O(w)
            unordered_map<string, int> wd;
            int cnt = 0;//cnt记录滑动窗口中有多少字符串在words中，其作用是用来判断两个哈希表是否相等，cnt也是滑动窗口的状态记录
            for (int j = i; j + w <= n; j += w) {//每一组w个字符串一起考虑，最多n/w个字符串，每个字符串要放入哈希表，字符串push进哈希表的时间为字符串的长度w，所以这一步的时间为O(n/w * w) = O(n)
                if (j - m * w >= i) {//不在滑动窗口中，出队 
                    string s1 = s.substr(j - w * m, w);
                    if (wd[s1] <= hash[s1]) cnt--;
                    wd[s1]--;
                }
                string s2 = s.substr(j, w);//将当前字符串加入滑动窗口
                wd[s2]++;
                if (hash[s2] >= wd[s2]) cnt++;
                if (cnt == m) res.push_back(j - (m - 1) * w);
            }
        }
        return res;
    }
};