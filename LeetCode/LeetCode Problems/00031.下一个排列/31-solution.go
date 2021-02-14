//找规律题：从后往前找到第一个降序对nums[i-1], nums[i]，nums[i, len(nums))一定是降序的
//在nums[i, len(nums))中从后往前找第一个比nums[i-1]大的数nums[k]，交换nums[k]和nums[i-1]
//最后再把nums[i, len(arr))整理为升序，这一步可以reverse(nums[i:])完成（因为交换完之后一定是降序，reverse即为升序）
//时间复杂度O(n)，空间复杂度O(1)
func nextPermutation(nums []int)  {
    n := len(nums)
    i := n - 1
    for i - 1 >= 0 && nums[i - 1] >= nums[i] {
        i--
    }
    if i == 0 {
        reverse(nums[:])
        return
    }

    k  := n - 1
    for k >= i {
        if nums[k] > nums[i - 1] {
            nums[i - 1], nums[k] = nums[k], nums[i - 1]
            reverse(nums[i:])
            return;
        }
        k--
    }
}

func reverse(arr []int) {
    for i, j := 0, len(arr) - 1; i <= j; i++ {
        arr[i], arr[j] = arr[j], arr[i]
        j--
    }
}