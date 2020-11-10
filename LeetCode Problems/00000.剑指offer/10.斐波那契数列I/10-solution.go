func fib(n int) int {
    if n == 0 {
        return 0
    }
    if n == 1 {
        return 1
    }
    ppre, pre, res := 0, 1, 0
    
    for i := 2; i <= n; i++ {
        res = (ppre + pre) % 1000000007
        ppre, pre = pre, res
    }
    return res
}