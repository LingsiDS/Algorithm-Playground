//注意理解题意，只要执行完序列化再执行反序列化之后能够恢复原树即可，序列化方式任意
//时间复杂度O(n)
class Codec {
public:
    void encode(TreeNode* root, string &res) {
        if (root == NULL) {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ',';
        encode(root->left, res);
        encode(root->right, res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        encode(root, res);
        return res;
    }


    TreeNode* decode(int &idx, string &data) {
        if (idx >= data.size()) {
            return NULL;
        }
        int i = idx;
        while (data[i] != ',') i++;
        string val = data.substr(idx, i - idx);
        idx = i + 1;
        TreeNode* root = NULL;
        if (val != "#") {
            root = new TreeNode(stoi(val));
            root->left = decode(idx, data);
            root->right = decode(idx, data);
            return root;
        }
        return NULL;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return decode(idx, data);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));