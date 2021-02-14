//方法一：时间O(n*n)，空间O(1)将所有0冒泡
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;//已经排好序的0的数目
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                int t = i;
                while (t + 1 < n - cnt) {//使用冒泡排序的思想，把0交换到最后
                    swap(nums[t], nums[t+1]);
                    t++;
                }
                cnt++;
            }
        }
    }
};

//双指针：一个指针i记录所有非零元素的位置，初始化为0
//遍历数组，如果当前元素不是0，则将当前元素放入下标为i的位置，i++，如果是0，则不需要操作
//如果i没有指向数组的末尾，将i之后的所有元素设置为0
//时间O(n)，空间O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) nums[i++] = nums[j];
        }
        while (i < nums.size()) nums[i++] = 0;
    }
};