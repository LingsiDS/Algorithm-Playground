/*贪心：如果遇到一段连续上升/下降的序列，一定要取其中的最大/最小元素，只有这样序列长度才可能更长 ：)

关于为什么这样贪心，官方题解解释的不错:如果「过渡元素」在选择的序列中小于其两侧的元素，
那么「谷」一定没有在选择的序列中出现，我们可以将「过渡元素」替换成「谷」；
同理，如果「过渡元素」在选择的序列中大于其两侧的元素，那么「峰」一定没有在选择的序列中出现，
我们可以将「过渡元素」替换成「峰」。

遍历一遍数组，使用栈来保存摆动序列，时间复杂度为O(n), 空间复杂度O(n)，注意只需要求摆动序列长度，
而且栈只用到了栈最上面2个元素，空间可以优化为O(1)，参考官方题解后，见python代码
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> stk;
        stk.push_back(nums[0]);
        int d = 0;//d表示方向，大于0表示当前是上升序列，要找下降序列，小于0表示当前是下降序列，要找上升序列
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= stk[stk.size() - 1] && d > 0) {//连续上升区间，上升元素中最大的
                stk.pop_back();
                stk.push_back(nums[i]);
            }
            else if (nums[i] <= stk[stk.size() - 1] && d < 0) {//连续下降区间，选择下降区间中最大的
                stk.pop_back();
                stk.push_back(nums[i]);
            } else {//找到了一个摆动序列
                if (nums[i] == stk[stk.size() - 1]) continue;//相等的元素不加入
                stk.push_back(nums[i]);
                d = stk[stk.size() - 1] - stk[stk.size() - 2];//更新方向
            }
        }
        return stk.size();
    }
};