//时间复杂度O(n), 空间复杂度O(n)，如何把空间复杂度优化为常数？
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;
        int m = INT_MIN;
        for (auto &n : nums) {
            st.insert(n);
            if (n > m) m = n;
        }
        
        int idx = 1;
        while (idx <= m) {
            if(st.count(idx) == 0) return idx;
            idx++;
        }
        return idx;
    }
};


//假设数组大小为n，如果里面的数刚好为1到n，则答案为n+1，否则答案一定在[1,n]之间
//所以我们可以利用原数组作为哈希表，遍历数组假设x = nums[i], 则我们把x放到nums[x - 1]（数组下标从0开始）
//的位置上，经过这样的操作，我们期待的数组的顺序应该为[1,2,3,4,5,6,7,...]，nums[i] 应该在下标为 nums[i] - 1的位置
//再一次遍历nums，如果对应位置上的数不是我们所期待的，则返回该位置下标加1。如果数组中存在某数不在[1,n]之间，
//如果这样的数存在，则数组中的数必然不是包含从1到n的所有数，其中某些数必定有缺失，对于数组中不在[1,n]之间的数
//我们不需要考虑将其交换到某位置，待其它在[1,n]范围内的数放到它们应该在的位置，超出范围的数则放到了某个缺失的数应该在的位置
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            //对于不在[1, n]之间的数，不需要考虑，如果nums[i]不在其“期待”的位置nums[i] - 1
            while (nums[i] > 0 && nums[i] <= n && nums[i]  != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);   //将nums[i] 放置到其应该在的位置。
        }

        //利用原数组作为哈希表，判断方法为下标为i的数，其值nums[i]一定为i+1
        for (int i = 0; i < n; i++) 
            if (nums[i] != i + 1) return i + 1;//否则该数为最小的缺失的正整数（因为其他在[1,n]范围内的数都在它们应该在的位置上）
        return n + 1;
    }
};