//贪心题，难点在于证明算法的正确性，首先我们定义函数check(a, b)表示检查a的前缀和b的后缀是否构成回文
//如果要检测a的后缀和b的前缀是否构成回文则调用check(b, a)即可。
//check的工作过程首先是定位a的前缀和b的后缀最长可以匹配的位置，while (a[i] == b[j]) i++, j--；
//这样在i，j两端的子串一定能构成回文，接下来考虑如果切分点在a[i-1]（a[i-1]属于前半段）的位置，切分后如果a[i~j]能够构成回文
//则a[0~i-1] + a[i ~ j] + b[j~b.size()-1]构成的子串一定是回文的，这是因为构成这个子串的各个部分都是回文的；
//如果切分点是在b[j]（b[j+1]属于后半段）的位置，只需要考虑b[i~j]是否构成回文，如果其构成回文，则a[0~i-1] + b[i~j] + b[j+1 ~ b.size()-1]
//也是回文串。
//以上过程关键是为什么只用考虑两个分割点a[i-1],b[j]，首先如果分割点在i的前面或者j的后面，并且假设分割后组合起来能得到回文串，
//那么我们考虑的分割点a[i-1]和b[j+1]也一定能构成回文，所以我们不考虑在i之前或者j之后的分割点。
//如果分割点在i，j之间，如果能构成回文，那么说明我们找的匹配的公共前后缀不是最长的，与实际矛盾，所以在i，j之间的分割点
//一定不能构成回文，所以只需要考虑分割点在a[i-1]和b[j+1]，考虑a[i~j]与b[i~j]是否能构成回文即可。

//算法时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        if (a.size() == 0) return true;
        return check(a, b) || check(b, a);
    }

    bool check(const string &a, const string &b) {
        int i = 0, j = b.size()-1;
        while (a[i] == b[j]) i++, j--;//找最长匹配的前后缀
        return isPalindrome(a, i, j) || isPalindrome(b, i, j);//如果a[i~j]或者b[i~j]构成回文则整个串为回文
    }

    bool isPalindrome(const string &a, int i, int j) {
        while (i <= j && a[i] == a[j]) i++, j--;
        return i >= j;
    }
};