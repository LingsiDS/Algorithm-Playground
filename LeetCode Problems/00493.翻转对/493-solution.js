//c++味的js  :)
var reversePairs = function(nums) {
    var res = 0;

    var t = new Array(50010).fill(0);
    var merge_sort = function(q, l, r) {
        if (l >= r) return;
        
        //默认浮点数除法
        var mid = Math.floor((l + r) / 2); 
        merge_sort(q, l, mid);
        merge_sort(q, mid + 1, r);

        //双指针统计
        var x = l, y = mid + 1;
        while (x <= mid && y <= r) {
            if (q[x] > q[y] * 2) {
                res += mid - x + 1;
                y++;
            } else x++;
        }

        //归并
        var i = l, j = mid + 1, idx = 0;
        while (i <= mid && j <= r) {
            if (q[i] <= q[j]) t[idx++] = q[i++];
            else t[idx++] = q[j++];
        }
        while (i <= mid) t[idx++] = q[i++];
        while (j <= r) t[idx++] = q[j++];

        for (let i = l, k = 0; i <= r; i++, k++) q[i] = t[k];
    }

    merge_sort(nums, 0, nums.length - 1);
    return res;
};

