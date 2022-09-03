arr = input()
m = len(arr)
n = m
if n > 9:
    n = (n-9)//2 + 9

ans = [0] * n
used = [False] * (n+1)
def backtrack(pos, s):
    if pos == n:
        for u in used[1:]:
            if not u: return False
        print(*ans, sep=" ")
        return True
    for i in (1,2):
        e = s+i
        if e > m: break
        num = int(arr[s:e])
        if num > n: continue
        if used[num]: continue
        ans[pos] = num
        used[num] = True
        if backtrack(pos+1, e):
            return True
        ans[pos] = 0
        used[num] = False

backtrack(0,0)