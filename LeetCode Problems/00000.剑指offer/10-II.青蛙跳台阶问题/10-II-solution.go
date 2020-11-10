func numWays(n int) int {
    if n == 0 {//没有台阶不走，是1种方案
        return 1
    }
    if n == 1 {//1级台阶，只有一种走法
        return 1
    }
    a, b, res := 1, 1, 0
    for i := 2; i <= n; i++ {
        res = (a + b) % 1000000007  //有两种方法到达第n级台阶，分别是从第n-1,n-2级台阶走1步或2步上来
        a, b = b, res
    }
    return res
}