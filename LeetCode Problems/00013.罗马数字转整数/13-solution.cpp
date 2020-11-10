class Solution {
public:
    unordered_map<char, int> hash; 
    int romanToInt(string s) {
        //将所有罗马数字对应的值存到哈希表中
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;
        
        int res = 0;
        //从左向右遍历字符串s
        for (int i = 0; i < s.size(); i++) {
            //不论如何，先加上当前罗马数字对应的数值
            res += hash[s[i]];

            //如果前一个罗马数字对应的数值小于当前罗马数字对应的数值，则这两个罗马数字应该一起考虑
            if (i - 1 >= 0 && hash[s[i-1]] < hash[s[i]]) {
                res -= hash[s[i]];     //减去当前罗马数字对应的数值
                res -= hash[s[i-1]];   //减去前一个罗马数字对应的数值
                res += hash[s[i]] - hash[s[i-1]];   //将这两个罗马数字一起考虑
            }
        }
        return res;
    }
};