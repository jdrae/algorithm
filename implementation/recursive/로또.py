comb = [0 for _ in range(6)]
def func(pos, cnt):
    if cnt == 6:
        for c in comb: print(c, end=" ")
        print()
        return
    for i in range(pos, k):
        comb[cnt] = s[i]
        func(i+1,cnt+1)

while True:
    k, *s = map(int, input().split())
    if k == 0: break
    func(0, 0)
    print()