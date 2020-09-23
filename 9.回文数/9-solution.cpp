//反转x再和x比较
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;    
        long long res = 0;
        int y = x;
        while (x) {//依次将x的低位转换到高位
            res = res * 10 + x % 10;
            x = x / 10;
        }
        return y == res;
    }
};


//反转x的后半段，再和x的前半段比较，判断情况太多
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x % 10 == 0 && x != 0) return false;//如果末尾有0，且该数不为0，return false
        if (x == 0) return true;
        int res = 0;
        while (res < x) {//while stop when: res >= x 
            res = res * 10 + x % 10;
            x /= 10;
        }
        return x == res || x == res / 10;
    }
};