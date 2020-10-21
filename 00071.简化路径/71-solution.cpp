//将每个目录名存入vector中，如果遇到".."，则将最后的元素弹出，最后把所有目录名以'/'串连起来
//时间复杂度：遍历一遍字符串O(n)，空间复杂度O(m)，目录数
class Solution {
public:
    string simplifyPath(string path) {
        string res;
        vector<string> stk;

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') continue;
            else {
                int j = i + 1;
                while (j < path.size() && path[j] != '/') j++;//path[j] == '/'
                string t = path.substr(i, j-i);     //获取两个'/'之间的目录名
                if (t == ".") continue;             //如果是'.'，continue
                else if (t == ".." && stk.size()) stk.pop_back();   //如果是".."，并且还有上级目录，进入上级目录
                else if (t != "..") stk.push_back(t);   //否则记录目录名，注意上一个判断可能会遇到".."并且stk为空的情况，不能将".."记录下来，过滤这种情况
                i = j;
            }
        }

        for (int i = 0; i < stk.size(); i++) {
            res.push_back('/');
            res += stk[i];
        }
        if (res == "" && path.size()) res += "/";
        return res;
    }
};