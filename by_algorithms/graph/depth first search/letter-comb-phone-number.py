from typing import List

class Solution:
    def __init__(self):
        self.ans = []
        self.digits = ""
        self.alp = {"2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"}

    def dfs(self, comb, pos):
        if pos == len(self.digits):
            self.ans.append(comb)
            return
        
        for cand in self.alp[self.digits[pos]]:
            self.dfs(comb+cand,pos+1)
        return

    def letterCombinations(self, digits: str) -> List[str]:
        if not digits: return []
        self.digits = digits
        
        self.dfs("", 0)
        
        return self.ans
        

res = Solution().letterCombinations("23")
print(res)

res = Solution().letterCombinations("")
print(res)

res = Solution().letterCombinations("2")
print(res)


res = Solution().letterCombinations("4598")
print(res)