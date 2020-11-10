import re
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.rstrip()
        return len(re.split(r'[ ]+', s)[-1])
