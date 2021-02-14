//在原地把退格以及退格之前的字符替换为' '，然后再使用双指针进行比较、
//总共需要扫描两个字符串2次，时间复杂度为O(n+m)，空间复杂度为O(1)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        build(S);
        build(T);

        //双指针检查是否相等
        int i = 0, j = 0;
        while (i < S.size() && j < T.size()) {
            if (S[i] == ' ') {
                i++;
                continue;
            } 
            if (T[j] == ' ') {
                j++;
                continue;
            }
            if (S[i++] != T[j++]) return false;
        }
        while (i < S.size()) {
            if (S[i++] != ' ') return false;
        }
        while (j < T.size()) {
            if (T[j++] != ' ') return false;
        }
        return true;
    }

    //遇到#把当前字符以及前一个字符替换为' '
    void build(string& s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
               s[i] = ' ';
               int idx = i - 1;
               while (idx >= 0 && s[idx] == ' ') {
                   idx--;
               } 
               if(idx >= 0) s[idx] = ' ';
            }
        }
    }
};

//使用字符串作为栈，时间复杂度O(n + m)，空间复杂度为O(max(n, m))
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return build(S) == build(T);
    }

    //遍历字符串s，如果遇到'#'且栈顶非空，将元素出栈，否则入栈
    string build (string &s) {
        string ret;//使用字符串当做栈来使用，需要额外空间
        for (auto c: s) {
            if (c != '#') {
                ret.push_back(c);
            }
            else if (!ret.empty()) ret.pop_back();
        }    
        return ret;
    }
};