/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func getMinimumDifference(root *TreeNode) int {
    pre, res := -1, math.MaxInt64
    var dfs func(*TreeNode)
    dfs = func (root *TreeNode) {
        if root == nil {
            return
        }
        dfs(root.Left)
        if pre == -1 {
            pre = root.Val
        } else {
            if root.Val - pre < res {
                res = root.Val - pre
            }
            pre = root.Val
        }
        dfs(root.Right)
    }
    dfs(root)
    return res;
}