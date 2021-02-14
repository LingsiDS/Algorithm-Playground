//数学，O(n)
func cuttingRope(n int) int {
    if n == 2 {
        return 1
    }
    if n == 3 {
        return 2
    }
    res := 1
    for n >= 5 {
        n -= 3
        res *= 3;
    }
    return n * res
}