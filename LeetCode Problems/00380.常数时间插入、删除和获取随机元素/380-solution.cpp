//第381题的子问题，381中允许元素重复，这里元素不重复
class RandomizedSet {
public:
    unordered_map<int, int> hash;
    vector<int> data;

    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool res = false;
        if (hash.count(val) == 0) res = true;
        data.push_back(val);//将数据存入数组中
        hash[val] = data.size() - 1;//记录val在数组中的位置
        return res;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool res = false;
        if (hash.count(val)) {//元素存在才执行remove操作
            res = true;
            int px = hash[val], py = data.size() - 1;//删除元素的下标和数组最后元素的下标
            int y = data[py];
            swap(data[px], data[py]);//将要删除的元素交换到数组末尾，删除数组末尾元素
            data.pop_back();
            hash[y] = px;//更新y的下标
            hash.erase(val);//哈希表中删除val
        }
        return res;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return data[rand() % data.size()];//等概率返回数组中的元素
    }
};