"""
UF 최종 결과의 값이 수퍼부모가 아닐 수 있음. [0,0,1] 처럼
"""

def toc(idx):
    return idx//n, idx%n
def toi(y,x):
    return y*n + x

def find(a):
    if uf[a] == a: return a
    uf[a] = find(uf[a])
    return uf[a]

def merge(a, b):
    a, b = find(a), find(b)
    if a == b: return
    if a < b: uf[b] = a
    else: uf[a] = b
    return

if __name__ == "__main__":
    # input
    n, l, r = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(n)]

    # 국경선
    pairs = set([])
    dy = [-1,1,0,0]
    dx = [0,0,-1,1]
    for y in range(n):
        for x in range(n):
            for i in range(4):
                ny, nx = y+dy[i], x+dx[i]
                if 0<=ny<n and 0<=nx<n:
                    p, q = toi(y,x), toi(ny,nx)
                    if (p,q) in pairs or (q,p) in pairs: continue
                    pairs.add((p,q))

    ans = 0
    while True:
        uf = [i for i in range(n*n)]
        dic = {k:[0,0] for k in range(n*n)}
        # 차이 계산
        cnt = 0
        for p,q in pairs:
            if uf[p] != uf[q]:
                y, x = toc(p)
                pval = arr[y][x]
                y, x = toc(q)
                qval = arr[y][x]
                if l <= abs(pval-qval) <= r:
                    merge(p,q)
                    cnt += 1

        # 다 닫혀있을 시
        if cnt == 0:
            break

        # uf 최종
        for idx, par in enumerate(uf):
            uf[idx] = find(par)

        # 인구수 변경
        is_changed = 0
        for idx, par in enumerate(uf):
            y, x = toc(idx)
            dic[par][0] += arr[y][x]
            dic[par][1] += 1
        for idx, par in enumerate(uf):
            y, x = toc(idx)
            tmp = dic[par][0] // dic[par][1]
            if tmp != arr[y][x]:
                arr[y][x] = tmp
                is_changed += 1

        # 변경 없을 시
        if not is_changed:
            break

        # 날짜 카운트
        ans += 1
print(ans)