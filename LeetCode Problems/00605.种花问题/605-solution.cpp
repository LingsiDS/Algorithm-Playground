//贪心，丑陋写法，时间复杂度O(m)，空间复杂度O(1)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if (i == 0 && !flowerbed[i]){
                if (i + 1 < m) {
                    if (!flowerbed[i + 1]) {
                        flowerbed[i] = 1;
                        cnt++;
                    }
                }
                else {
                    flowerbed[i] = 1;
                    cnt++;
                }
            } 
            else if (i == m - 1 && !flowerbed[i]) {
                if (i - 1 >= 0) {
                    if (!flowerbed[i - 1]) {
                        cnt++;
                        flowerbed[i] = 1;
                    }
                } else {
                    if(!flowerbed[i - 1]) {
                        cnt++;
                        flowerbed[i] = 1;
                    }
                }
            }
            else if (!flowerbed[i] && !flowerbed[i - 1] &&  !flowerbed[i + 1]) {
                cnt++;
                flowerbed[i] = 1;
            }
        }
        return cnt >= n;
    }
};


