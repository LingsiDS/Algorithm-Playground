# 关键理清题意，有2种不合法情况，第一种为相同字符对应不同字符串，第二种为不同字符对应相同字符串
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(' ')
        if len(words) != len(pattern):
            return False
        st = set()
        dic = {}
        for i, p in enumerate(pattern):
            if p in dic:
                if dic[p] != words[i]:# 情况1
                    return False
            else:
                if words[i] in st:# 情况2
                    return False
                dic[p] = words[i]
                st.add(words[i])

        return True