struct Node {
    Node* son[26] = {0};
    bool ed = false;
};

class Trie {
public:
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node;//头结点
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for (int i = 0; i < word.size(); i++) {
            int u = word[i] - 'a';
            if (!(p->son[u])) (p->son[u]) = new Node;
            p = p->son[u];
        }
        p->ed = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = root;
        for (int i = 0; i < word.size(); i++) {
            int u = word[i] - 'a';
            if (!(p->son[u])) return false;
            p = p->son[u];
        }
        return p->ed;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = root;
        for (int i = 0; i < prefix.size(); i++) {
            int u = prefix[i] - 'a';
            if (!(p->son[u])) return false;
            p = p->son[u];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */