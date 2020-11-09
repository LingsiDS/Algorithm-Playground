//API：func ReplaceAll(s, old, new string) string
//ReplaceAll returns a copy of the string s with all non-overlapping instances of old replaced by new.
func replaceSpace(s string) string {
    return strings.ReplaceAll(s, " ", "%20")
}

//遍历
func replaceSpace(s string) string {
    var res string
    for i := 0; i < len(s); i++ {
        if (s[i] != ' ') {
            res += string(s[i])
        } else {
            res += string("%20")
        }
    }
    return res;
}