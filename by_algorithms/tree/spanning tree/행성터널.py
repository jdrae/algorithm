# solve again
# input
n = int(input())
xcoor, ycoor, zcoor = [], [], []
for idx in range(n):
    x, y, z = map(int, input().split())
    xcoor.append((x,idx))
    ycoor.append((y,idx))
    zcoor.append((z,idx))

xcoor.sort()
ycoor.sort()
zcoor.sort()

edges = []
for i in range(n-1):
    edges.append((xcoor[i+1][0]-xcoor[i][0], xcoor[i][1], xcoor[i+1][1]))
    edges.append((ycoor[i+1][0]-ycoor[i][0], ycoor[i][1], ycoor[i+1][1]))
    edges.append((zcoor[i+1][0]-zcoor[i][0], zcoor[i][1], zcoor[i+1][1]))
edges.sort(key=lambda x: x[0])

# unionfind
p = [-1 for _ in range(n)]
def find(a):
    if p[a] < 0: return a
    p[a] = find(p[a])
    return p[a]

def merge(a, b):
    a, b = find(a), find(b)
    if a == b: return False
    p[b] = a
    return True

# kruskal
mst, cnt = 0, 0
for w, u, v in edges:
    if merge(u,v):
        mst += w
        cnt += 1
        if cnt == n-1: break
print(mst)
