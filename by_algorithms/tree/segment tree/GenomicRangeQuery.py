import math

def construct(S):
    tree_h = math.ceil(math.log(len(S),2))
    tree_size = 1 << (tree_h + 1)
    tree = [4] * tree_size
    leaf = tree_size >> 1
    i, j = leaf, 0
    while i < tree_size:
        if j < len(S):
            tree[i] = S[j]
        i+=1
        j+=1
    for i in range(leaf-1, 0, -1):
        tree[i] = min(tree[i*2], tree[i*2+1])
    return tree, leaf

def find(tree, l, r, nnum, nl, nr):
    if r < nl or l > nr: return 4
    if l <= nl and nr <= r : return tree[nnum]
    mid = (nl+nr) // 2
    return min(find(tree, l,r,nnum*2, nl, mid), find(tree, l,r,nnum*2+1, mid+1, nr))

def solution(S, P, Q):
    dic = {"A":1,"C":2,"G":3,"T":4}
    arr = [dic[s] for s in S]
    tree, leaf = construct(arr)
    print(leaf, tree)
    ans = []
    for i in range(len(P)):
        l, r = P[i], Q[i]
        ans.append(find(tree, l, r, 1, 0, leaf-1))
    return ans

print(solution("GATCCT",[0,3,5],[5,5,5]))