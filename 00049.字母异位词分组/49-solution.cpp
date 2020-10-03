//使用哈希表，key为string，val为vector<string>，所有异位词经过排序后一定相等，
//遍历字符数组，将每个字符串排序后作为key，将原字符串作为val加入对应key的字符数组中
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++) {//n = strs.size(), O(n)
            string s = strs[i];//m = s.size()
            sort(s.begin(), s.end());//mlog(m)
            hash[s].push_back(strs[i]);//可以使用hash[s].push_back(move(strs[i]))，提高效率
        }

        for (auto it = hash.begin(); it != hash.end(); it++) {
            res.push_back(it->second);//直接push vector对象会调用复制构造函数，可以使用res.push_back(move(it->second))，减少内存拷贝
        }
        return res;
    }
};