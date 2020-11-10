class RandomizedCollection {
public:
    //哈希表存储val在数组中的下标，为了支持下标的O(1)时间内插入和删除，再次使用哈希表存储下标
    unordered_map<int, unordered_set<int>> hash;
    //存储数据，可以重复，随机返回一个数时，只要随机数组的下标值即可等概率返回元素
    vector<int> data;
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = false;
        if (hash[val].empty()) {//在数组中还没有该元素
            res = true;
        }
        data.push_back(val);
        int sz = data.size() ? data.size() - 1: 0;
        hash[val].insert(sz);//插入val在数组中的下标
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        int res = false;
        if (!hash[val].empty()) {
            res = true;
            int px = *hash[val].begin(), py = data.size() - 1;//分别表示val，和最后一个元素在数组中的下标
            int y = data[py];//最后一个元素的值
            swap(data[px], data[py]);//将要删除的元素放到最后，然后pop_back删除该元素
            data.pop_back();
            hash[val].erase(px);//同时删除该元素的下标
            hash[y].insert(px);//y被换到val的位置上，删除y原来的位置，插入新的位置
            hash[y].erase(py);
        }
        return res;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return data[rand() % data.size()];
    }
};
