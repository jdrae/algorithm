n = int(input())
tree=[[] for _ in range(n+1)]
indegree = [0]*(n+1)
for _ in range(n):
    p, l, r = map(int,input().split())
    tree[p].append(l)
    tree[p].append(r)
    if l!=-1:
        indegree[l]+=1
    if r!=-1:
        indegree[r]+=1

root=0
for i in range(1,n+1):
    if indegree[i]==0:
        root=i

# 중위순회
level= [[] for _ in range(n+1)] 
col=1
def inorder(curr,row):
    global col
    if curr == -1: return
    inorder(tree[curr][0],row+1)
    level[row].append(col)
    col+=1
    inorder(tree[curr][1],row+1)
inorder(root,1)

# 너비계산
lv, mx=1,0
for i in range(1,n+1):
    if not level[i]: continue
    res = max(level[i]) - min(level[i]) + 1
    if mx < res:
        lv = i
        mx = res
print(lv, mx)