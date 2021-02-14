//使用哈希表，需要额外空间
class Solution {
public:
    vector<int> res;
    unordered_map<int, int> hash;
    int m = 0;
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root) {
        if (root == NULL) return;

        if (hash.count(root->val)) {
            hash[root->val]++;
        }
        else hash[root->val] = 1;
        
        if (hash[root->val] == m) {
            res.push_back(root->val);
        }
        if (hash[root->val] > m) {
            res.clear();
            res.push_back(root->val);
            m = hash[root->val];
        }
        dfs(root->left);
        dfs(root->right);
    }
};


//不需要额外空间
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        travel(root);
        return answer;
    }

    int base, count, maxCount;
    vector<int> answer;

    void update(int x) {
        if (x == base) {
            ++count;
        } else {
            count = 1;
            base = x;
        }
        //以下判断每次都执行
        if (count == maxCount) {
            answer.push_back(base);
        }
        if (count > maxCount) {
            maxCount = count;
            answer = vector<int> {base};
        }
    }

    //Morris遍历，空间复杂度O(1)
    void travel(TreeNode* root) {
        if (root == NULL) return;
        while (root) {
            if (root->left == NULL) {
                update(root->val);
                root = root->right;
                continue;
            }
            else {
                TreeNode* pre = root->left;
                //查找左子树先驱，pre->right != root
                while (pre->right && pre->right != root) pre = pre->right;
                if (pre->right == NULL) {
                    pre->right = root;
                    root = root->left;
                }
                else {//已经访问完左子树，访问根节点
                    pre->right = NULL;//恢复指针
                    update(root->val);
                    root = root->right;
                }
            }
        }
    }
};

