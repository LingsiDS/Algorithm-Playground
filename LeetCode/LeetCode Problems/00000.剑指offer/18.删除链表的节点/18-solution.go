//使用一个pre指针遍历，时间复杂度O(n)
func deleteNode(head *ListNode, val int) *ListNode {
    pre := new(ListNode)
    pre.Next = head
    res := pre
    for head != nil && head.Val != val {
        pre = pre.Next
        head = head.Next
    }
    pre.Next = head.Next
    return res.Next
}