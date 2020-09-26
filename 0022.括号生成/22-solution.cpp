class Solution {
public:
    vector<string> res;
    string s;
    vector<string> generateParenthesis(int n) {
        dfs('(', 0, 1, 0, n);//第一个位置只能放左括号
        return res;
    }

    //c当前放置的括号，cnt匹配括号数，l放置左括号数，r放置右括号数
    void dfs(char c, int cnt, int l, int r, int n) {
        s += c;
        if (cnt == n) {
            res.push_back(s);
            return;
        }

        if (l != n) {//还可以放左括号
            dfs('(', cnt, l + 1, r, n);
            s.pop_back();
        }    
        if (l > r ) {//左括号数大于右括号数才能放括号
            dfs(')', cnt + 1, l, r + 1, n);
            s.pop_back();
        } 
    }
};