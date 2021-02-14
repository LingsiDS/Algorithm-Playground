//get put 时间复杂度O(1)
//key，val对存储在双向链表中，同时为了高效查找一个key是否在链表中，使用哈希表存储一个key到Node*
//的映射，通过哈希表可以判断key是否存在，如果存在取出key对应的val，以上操作在O(1)时间内即可完成。
//在双向链表中维护LRU机制，最近使用过的数据放在链表开头，链表的插入和删除操作都是O(1)的，
//当Cache已满并且还需要插入数据时，只需要删除链表最后一个节点，将新数据插入链表的开头即可。
class LRUCache {
public:
    struct Node {
        int key, val;
        Node *left, *right;
        Node(int _key, int _val):key(_key), val(_val), left(NULL), right(NULL){}
    };
    Node *L, *R;
    unordered_map<int, Node*> hash;
    int sz = 0;

    void remove(Node *p){//从链表中删除节点p
        p->left->right = p->right;
        p->right->left = p->left;
    }
    void insert(Node *p) {//将节点p插入到链表开头
        p->left = L;
        p->right = L->right;
        L->right->left = p;
        L->right = p;
    }

    LRUCache(int capacity) {
        sz = capacity;
        L = new Node(-1, -1);
        R = new Node(-1, -1);
        L->right = R;
        R->left = L;
    }
    
    int get(int key) {
        if (hash.count(key) == 0) return -1;
        auto p = hash[key];
        remove(p);
        insert(p);//使用过，放到链表的最前
        return p->val;
    }
    
    void put(int key, int value) {
        if (hash.count(key) != 0) {//存在
            auto p = hash[key];
            p->val = value;//修改value
            remove(p);
            insert(p);//使用过，放到链表的最前
        }
        else {//不存在
            auto p = new Node(key, value);//创建新节点
            if (hash.size() == sz) {//缓存满了
                auto t = R->left;
                hash.erase(R->left->key);
                remove(R->left);
                delete(t);
            }
            insert(p);//将新节点插入缓存
            hash[key] = p;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */