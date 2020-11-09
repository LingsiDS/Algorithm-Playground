/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 //先遍历一遍链表，将链表存储到数组中，之后，在反向遍历数组即可，时间复杂度O(n)，空间复杂度O(n)
func reversePrint(head *ListNode) []int {
    var hash [] *ListNode //slice 动态数组
    var res []int //slice
    for head != nil {
        hash = append(hash, head)
        head = head.Next
    }

    for i := len(hash) - 1; i >= 0; i-- {
        res = append(res, hash[i].Val)
    }
    return res;
}