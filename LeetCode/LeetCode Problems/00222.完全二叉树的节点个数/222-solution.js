//类似二分的思想
var countNodes = function(root) {
    if (!root) return 0;
    var l = root.left, r = root.right;
    var x = 1, y = 1;
    while (l) {
        x++;
        l = l.left;
    }
    while (r) {
        y++;
        r = r.right;
    }
    if (x == y) return (1 << x) - 1;
    else return countNodes(root.left) + 1 + countNodes(root.right);
};