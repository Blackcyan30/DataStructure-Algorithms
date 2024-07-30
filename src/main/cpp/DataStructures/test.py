from typing import List
class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for word in strs:
            res += str(len(word)) + "#" + word 
        return res

    def decode(self, s: str) -> List[str]:
        if s == "":
            return []
        i, res = 0, []
        while i < len(s):
            j = i
            while s[j] != "#":
                j += 1
            word_len = int(s[i:j])
            i = j + 1
            j = i + word_len
            res.append(s[i:j])
            i = j
        
        return res

test = ["we","say",":","yes","!@#$%^&*()"]

sol = Solution()

print(sol.encode(test))
print()
print(sol.decode(sol.encode(test)))