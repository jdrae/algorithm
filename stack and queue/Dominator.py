def solution(A):
    n = len(A)
    size = 0
    for k in range(n):
        if size == 0:
            size += 1
            value = A[k]
        else:
            if value != A[k]:
                size -= 1
            else:
                size += 1
    
    candidate = value if size > 0 else -1
    ans, cnt = -1, 0
    for k in range(n):
        if A[k] == candidate:
            cnt += 1
            ans = k

    if cnt <= n // 2:
        ans = -1
    return ans