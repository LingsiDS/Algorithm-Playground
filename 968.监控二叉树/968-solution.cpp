/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//一个节点有如下三种状态
 const int UNCOVER = 0;//没有被覆盖
 const int CAMERA = 1;//有摄像头
 const int COVER = 2;//被覆盖


class Solution {
public:
    int res = 0;
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) res++;
        return res;
    }

    int dfs(TreeNode* root) {
        if (root == NULL) return 2;//空节点的状态为被覆盖，这样空节点不会对其他节点造成影响

        //自底向上遍历（后续遍历），因为先让底部节点摄像头放置数量最少，越往上分支合并不会造成特殊情况
        //如果自上向下遍历，保证了树上方摄像头数量最少，但是越往下分支越多会，为了监控下放节点摄像头数量会更多
        int l = dfs(root->left), r = dfs(root->right);
        
        //左右子树都是有覆盖，则当前节点为无覆盖
        if (l == 2 && r == 2) return 0;
        
        //左右子树只要有一个节点是无覆盖，则当前节点必须为有摄像头
        if (l == 0 || r == 0) {
            res++;
            return 1;
        }
        
        //左子树或者右子树中有一个有摄像头（不可能出现无覆盖情况，上面已经处理过），则当前节点状态为有覆盖
        if (l == 1 || r == 1) return 2;
        
        return -1;
    }
};