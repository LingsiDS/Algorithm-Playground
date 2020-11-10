//双指针，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        
        int i = 0, j = n - 1;
        while (i <= j) {
            swap(s[i], s[j]);
            i++, j--;
        }
    }
};