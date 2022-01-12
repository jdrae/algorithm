"""
L칸을 한번에 체크하면 예외사항을 구현하기 힘듦.
1칸씩 체크하고, 가능한 후보에서 L칸을 다시 체크할 것.
"""

def check(arr):
    def inner_check(s,e):
        for b in range(s,e):
            if 0<=b<n:
                if ar[b] != mn or visited[i][b]:
                    return False
                visited[i][b] = 1
            else:
                return False
        return True

    ans = 0
    visited = [[0]*n for _ in range(n)]
    for i in range(n):
        can_pass = True
        ar = arr[i]
        for a in range(n-1):
            if ar[a] == ar[a+1]:
                continue
            if abs(ar[a]-ar[a+1]) > 1:
                can_pass = False
                break

            mn = min(ar[a], ar[a+1])
            if ar[a] < ar[a+1]: # 상승
                can_pass = inner_check(a-l+1,a+1)
            else: # 하강
                can_pass = inner_check(a+1, a+1+l)
            if not can_pass: break

        if can_pass:
            ans += 1

    return ans

if __name__ == "__main__":
    n, l = map(int,input().split())
    arr = [list(map(int,input().split())) for _ in range(n)]
    tarr = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            tarr[i][j] = arr[j][i]
    ans = check(arr) + check(tarr)
    print(ans)