题意为在`nums`数组中找到两个数的下标`i`和`j`，$i < j$，，使得`nums[i] + nums[j] == target`，并且题目中保证数组中同一个元素不能使用两遍，所以`i != j`



#### 两遍哈希

第一遍遍历数组，将数组中的每个元素存入哈希表中。第二遍遍历时我们已知最后两数的和为`target`，并且当前遍历到`nums[i]`，则如果`nums[i]`是其中一个加数，另一个加数为`target - nums[i]`，由于第一遍遍历数组时已经将数组内的所有元素存入哈希表中，所以只需要在第二遍遍历`nums[i]`时判断`target - nums[i]`是否在哈希表中，如果在，则找到了另一个加数，输出即可。

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            hash.insert({nums[i], i}); //将数组内所有元素加入哈希表
        }
        for (int i = 0; i < nums.size(); i++) {
            if (hash.count(target - nums[i])) {//查找target - nums[i]是否在哈希表中，如果在则找到
                if (hash[target - nums[i]] == i) continue;//不能使用相同的数字
                ans.push_back(hash[target - nums[i]]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
```



#### 一遍哈希

实际上可以使用一遍遍历就可以完成上述操作

在遍历时，假设遍历到`nums[j]`，首先在哈希表中查找`target - nums[j]`是否在哈希表中，如果在，则找到了两个加数，输出，如果不在则将`nums[j]`加入到哈希表中。

上述算法是基于这样的思路，题意需要寻找`nums[i] + nums[j] == target`，由题意一定有这样的`i`，`j`且`i < j`，当我们顺序遍历`j`时，`i`一定在哈希表中

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans;
        for (int j = 0; j < nums.size(); j++) {
            if (hash.count(target - nums[j])) {
                int i = hash[target - nums[j]];
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
            hash[nums[j]] = j;
        }
        return ans;
    }
};
```

