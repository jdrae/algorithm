n, m = map(int,input().split())
arr = list(map(int,input().split()))

add, mn = 0, n+1
s, e = 0, 0
while True:
    if add >= m:
        # 정답
        mn = min(mn, e-s)
        # 포인터 옮김
        add -= arr[s]
        s += 1
    elif e == n: break
    else:
        add += arr[e]
        e += 1

if mn == n+1: mn = 0
print(mn)
