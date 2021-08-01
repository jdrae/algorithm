# input
v,e = map(int, input().split())
edges = []
for _ in range(e):
    u,v,w = map(int,input().split())
    edges.append((w,u,v))

# union find
p = [0 for _ in range(v+1)]

def find(a):
    if p[a] == 0: return a
    p[a] = find(p[a])
    return p[a]

def merge(a,b):
    a, b = find(a), find(b)
    if a == b: return False
    p[b] = a
    return True

# kruskal
edges.sort(key = lambda x: x[0])

mst = 0
for w, u, v in edges:
    if merge(u,v):
        mst += w

print(mst)
