# 时间复杂度O(n), 空间复杂度O(1)
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return len(nums)
        
        res = (1 if nums[1] - nums[0] == 0 else 2)
        preDiff = nums[1] - nums[0]  #差值
        for i in range(2, len(nums)):
            curDiff = nums[i] - nums[i - 1]
            # 对于连续上升/下降的区间不需要额外操作，我们只需要找到峰顶or谷底即可
            if curDiff < 0 and preDiff >= 0 or curDiff > 0 and preDiff <= 0: #找到了一个摆动序列
                res += 1
                preDiff = curDiff
        return res