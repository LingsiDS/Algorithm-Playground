//定义一个idx表示符合条件的元素需要写入的下标位置，时间复杂大O(n)，空间复杂度O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0, cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1]) cnt++;//cnt统计重复次数
            else cnt = 1;
            
            if (cnt <= 2) {//重复小于2的填入nums[idx++]
                nums[idx++] = nums[i];
            } 
        }
        return idx;
    }
};