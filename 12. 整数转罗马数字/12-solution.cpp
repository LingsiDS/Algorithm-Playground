class Solution {
public:
    string intToRoman(int num) {
        //key为可以取的“面额”，val为“面额”对应的罗马字符
        vector<string> val{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> key{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans;
        for (int i = 0; i < key.size() && num;)  {//从大到小遍历，若num能转换为较大的数，则应先考虑较大的数
            if (num >= key[i]) {
                ans += val[i];
                num -= key[i];
            }
            else i++;//num < v[i]  i++尝试下一个
        }
        return ans;
    }
};