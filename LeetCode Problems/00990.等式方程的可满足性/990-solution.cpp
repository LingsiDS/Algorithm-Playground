//先遍历所有等式，将所有等式加入一个集合，再遍历所有不等式，如果不等式两个元素属于同一个集合则矛盾，返回false
//时间复杂度O(n)
class Solution {
public:
    int parent[26];
    int find(int x) {//并查集
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; i++) parent[i] = i;

        for (auto s: equations) {
            char a = s[0], b = s[3];
            char op = s[1];
            if (a == b && op == '=' || op == '!') continue;
            int ra = find(a - 'a'), rb = find(b - 'a');
            parent[ra] = rb;
        }

        for (auto s: equations) {
            char a = s[0], b = s[3];
            char op = s[1];
            if (op == '=') continue;
            int ra = find(a - 'a'), rb = find(b - 'a');
            if (ra == rb) return false;
        }
        return true;
    }
};