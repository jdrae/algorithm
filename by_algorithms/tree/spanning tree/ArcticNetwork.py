import math

uf = []

def find(a):
    if uf[a] < 0: return a
    uf[a] = find(uf[a])
    return uf[a]

def merge(a, b):
    a, b = find(a), find(b)
    if a == b: return False
    uf[b] = a
    return True

tc = int(input())
for _ in range(tc):
    s, p = map(int, input().split())
    coor = []
    for idx in range(p):
        x, y = map(int,input().split())
        coor.append((x,y,idx))

    edges = []
    for i in range(len(coor)):
        for j in range(i+1, len(coor)):
            # tip: 좌표 거리(빗변)
            edges.append((math.hypot(coor[i][0]-coor[j][0], coor[i][1]-coor[j][1]),coor[i][2],coor[j][2]))

    edges.sort(key=lambda x : x[0])

    # kruskal
    uf = [-1 for __ in range(p)]
    mst, cnt = 0, p - s 
    for w,u,v in edges:
        if merge(u,v):
            cnt -= 1
            mst = w
            if cnt == 0: break
    # tip: 실수 표현
    print("%.2f"%mst)