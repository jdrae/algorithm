
# union find
p = [i for i in range(51)]
def find(a):
    if p[a] == a: return a
    p[a] = find(p[a])
    return p[a]

def merge(a, b):
    a, b = find(a), find(b)
    if a == b: return
    if a == 0:
        p[b] = a
    else:
        p[a] = b

# input
n, m = map(int, input().split())
# tip: unpacking
_, *arr = map(int, input().split())
for a in arr: p[a] = 0

party = []
for _ in range(m):
    __, *tmp = map(int, input().split())
    prev = tmp[0]
    for i in tmp:
        merge(prev, i)
        prev = i

    group = find(tmp[0])
    party.append(group)

for i in range(len(party)):
    party[i] = find(party[i])

print(m - party.count(0))