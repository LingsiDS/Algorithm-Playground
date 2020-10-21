#split原字符串，结果存入列表res中，对于".."，pop出最后一个元素，最后"/".join(res)
#同时考虑最后边界情况，为了在最开头加上"/"，在res中最前面加入""
class Solution:
    def simplifyPath(self, path: str) -> str:
        if path == "":
            return path
        lst = path.split('/')
        
        res = [""]
        for p in lst:
            if p == '' or p =='.':
                continue
            if p == '..':
                if len(res) > 1:
                    res.pop()
                continue
            res.append(p)
        
        if "/".join(res) == "":
            return "/"
        else:
            return "/".join(res)

