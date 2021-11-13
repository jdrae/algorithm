arr = input()
m = len(arr)
n = m
if n > 9:
    n = (n-9)//2 + 9

found = False
ans = [0] * n
used = [False] * (n+1)
def backtrack(pos, s):
    global found
    if pos == n:
        if found: return
        for u in used[1:]:
            found = u
        print(*ans, sep=" ")
        return
    for i in (1,2):
        e = s+i
        if e > m: break
        num = int(arr[s:e])
        if num > n: continue
        if used[num]: continue
        ans[pos] = num
        used[num] = True
        backtrack(pos+1, e)
        ans[pos] = 0
        used[num] = False

backtrack(0,0)