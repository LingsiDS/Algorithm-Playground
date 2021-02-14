//注意旋转数组中可能有重复元素，基本思路，为二分，首先旋转后，数组后半段可能有元素和开头元素重复
//二分查找的范围中不考虑后半段的重复元素，然后二分旋转的分界点
//平均时间复杂度O(logn)，最坏时间复杂度O(n)，空间复杂度O(1)
func minArray(numbers []int) int {
    l, r := 0, len(numbers) - 1
    x := numbers[0]

    for r >= 0 && numbers[r] == x {//去除第二段数组中的重复元素，最坏情况下这一步的时间为O(n)
        r--
    }
    if r == 0 {//数组中所有元素都一样
        return numbers[r]
    }

    //二分过程
    for l < r {
        mid := (l + r + 1) / 2
        if numbers[mid] >= x {//二分第一段中最大的元素
            l = mid
        } else {
            r = mid - 1
        }
    }//二分完l是数组第一段中值最大的那个分界点

    if l == len(numbers) - 1 {//没有旋转，数组是升序的
        return numbers[0]
    } else {//l + 1 即为最小元素的位置
        return numbers[l + 1]
    }
    
}