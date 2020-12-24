//二叉搜索树的后序遍历序列为[左子树，右子树，根]，我们知道后序序列的最后一个元素就是根节点，然后从根节点往前找第一个小于根节点的元素
//这样就找出了左子树和右子树元素的范围，再判断左子树是否都小于根节点，然后递归判断左右子树是否是合法的后序遍历序列

//时间复杂度O(n^2)，空间复杂度O(n)
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() <= 2) return true;
        return dfs(postorder.size() - 1, 0, postorder.size() - 2, postorder);
    }

    bool dfs(int root, int l, int r, vector<int> &postorder) {//直观思路:以[l, r]的区间是否能构成二叉搜索树
        if (l >= r) return true;
        int rVal = postorder[root];
        int idx = r;
        while (idx >= 0 && postorder[idx] > rVal) idx--;//分界点
        int t = l;
        while (t <= idx)
            if (postorder[t++] > rVal) return false;//检查左子树中的所有节点是否都小于根节点
        if (idx == r) {
            return dfs(r, l, r - 1, postorder);//只有左子树
        } else {
            return dfs(r, idx + 1, r - 1, postorder) && dfs(idx, l, idx - 1, postorder);//递归检查左右子树
        }
        
    }
};


//O(n)做法