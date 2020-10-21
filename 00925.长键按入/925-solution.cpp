//双指针，时间复杂度O(n+m)，空间复杂度O(1)
//思路：如果匹配中遇到不等的字符return false，当name[i] == typed[j]，并且name[i + 1] != name[i] || i == name.size()-1时，跳过typed中所有相同的元素
//否则简单将两个指针加加，最后要检查name是否匹配完，typed是否有多余字符
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int pt1 = 0, pt2 = 0;
        while (pt1 < name.size() && pt2 < typed.size()) {
            if (name[pt1] != typed[pt2]) return false;
            if (pt1 == name.size() - 1 || (pt1 + 1 < name.size() && name[pt1] != name[pt1 + 1]) ) {//name要结束，或者遇到不同字符
                while (pt2 + 1 < typed.size() && typed[pt2] == typed[pt2 + 1]) pt2++;//将typed的所有相同字符跳过
            }
            pt1++;
            pt2++;
        }
        if (pt1 < name.size() || pt2 < typed.size()) return false;//没有匹配完name，或者多输入了无关字符
        return true;
    }
};


//官方解法，时间复杂度O(n+m)，空间复杂度O(1)：如果两个字符相等，则两个指针后移，否则，如果j - 1 >= 0 && typed[j] == typed[j-1]
//说明可以将此字符当做长按输入，j++跳过，否则返回false，最后检测是否匹配完了name
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < typed.size()) {
            if (i < name.size() && typed[j] == name[i]) {
                i++;
                j++;
            }
            else if (j - 1 >= 0 && typed[j] == typed[j-1]) {
                j++;//长按的输入
            }
            else return false;
        }
        return i == name.size();
    }
};