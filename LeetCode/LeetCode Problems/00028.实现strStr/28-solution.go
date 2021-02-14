//kmp模版题：时间复杂度O(m + n)
func strStr(haystack string, needle string) int {
    if len(needle) == 0 {
        return 0;
    }   
    var ne = make([]int, len(needle));//next 数组

    for i, j := 1, 0; i < len(needle); i++ {//求next数组
        for j != 0 && needle[i] != needle[j] {
            j = ne[j - 1]
        }
        if needle[i] == needle[j] {
            j++
        }
        ne[i] = j
    }

    for i, j := 0, 0; i < len(haystack); i++ {
        for j != 0 && haystack[i] != needle[j] {
            j = ne[j - 1]
        }
        if haystack[i] == needle[j] {
            j++
        }
        if j == len(needle) {
            return i - j + 1
        }
    }

    return -1;
}