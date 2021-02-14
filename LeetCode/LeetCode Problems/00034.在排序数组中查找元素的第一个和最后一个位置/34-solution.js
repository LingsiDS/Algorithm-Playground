//时间复杂度logn，空间复杂度O(1)
var searchRange = function(nums, target) {
    if (nums.length == 0) return [-1, -1];
    var l = 0, r = nums.length - 1;
    while (l < r) {
        var mid = Math.floor((l + r) / 2);
        if (nums[mid] >= target) r = mid;
        else l = mid + 1;
    }
    if (nums[l] != target) return [-1, -1];
    var res = [l];

    l = 0, r = nums.length - 1;
    while (l < r) {
        var mid = Math.floor((l + r + 1) / 2);
        if (nums[mid] <= target) l = mid;
        else r = mid - 1;
    }
    if (nums[l] != target) return [-1, -1];
    res.push(l);
    return res;
};