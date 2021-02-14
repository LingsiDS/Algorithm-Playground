//解题关键，将选择k个元素变换为删除nums.size() - k个元素，什么样的k个元素才有“资格”保留下来？
//答：该元素前面没有比该元素大的元素，否则删除当前元素前面比当前元素大的数，则会得到一个更小的数
//故理想状态下，最小的序列每一位应该是单调上升的，但是，最后需要保证最后留下k个数，故只能删除n - k
//个元素，而一个数的高位越小，则该数越小，故我们应该保证一个数的前半段尽可能小，
//故使用单调栈，找到一个前半段为单调上升的序列，后序序列直接复制进栈内即可，最后最小的一个
//长度为k的序列就是单调栈内前k个元素构成的序列

//时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int dt = nums.size() - k;//dt为需要删除的元素的个数

        vector<int> stk;//单调上升栈，注意可能不是完全单调的
        for (int i = 0; i < nums.size(); i++) {
            if (stk.empty()) {
                stk.push_back(nums[i]);
            } else {
                if (stk[stk.size() - 1] <= nums[i]) stk.push_back(nums[i]);
                else {
                    while (stk.size() && stk[stk.size() - 1] > nums[i] && dt) stk.pop_back(), dt--;//如果栈顶元素比当前元素大，则栈顶元素出栈，并且要删除的元素的个数dt减少1
                    stk.push_back(nums[i]);
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {//栈内前k个元素就是答案
            res.push_back(stk[i]);
        }
        return res;
    }
};