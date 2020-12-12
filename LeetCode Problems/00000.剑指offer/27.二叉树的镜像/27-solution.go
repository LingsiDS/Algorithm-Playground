func mirrorTree(root *TreeNode) *TreeNode {
    if root == nil || (root.Left == nil && root.Right == nil) {
        return root
    }
    root.Left, root.Right = mirrorTree(root.Right), mirrorTree(root.Left)
    return root
}