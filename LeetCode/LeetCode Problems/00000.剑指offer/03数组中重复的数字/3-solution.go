//使用哈希表，遍历数组，如果该元素不在哈希表中，则加入哈希表，否则该元素重复，返回该元素
//时间复杂度O(n)，空间复杂度O(n)
func findRepeatNumber(nums []int) int {
    var hash = make(map[int]bool)

    for i := 0; i < len(nums); i++ {
        if !hash[nums[i]] {
            hash[nums[i]] = true;
        } else {
            return nums[i]
        }
    }
    return -1;
}
