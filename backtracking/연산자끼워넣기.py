# input
n = int(input())
arr = list(map(int,input().split()))
a,b,c,d = map(int,input().split()) # + - * //

# backtracking
mn, mx = 1000000000, -1000000000
def func(res, pos, a,b,c,d):
    global n, mn, mx
    if pos == n:
        mx = max(mx, res)
        mn = min(mn, res)
        return
    if a:
        func(res + arr[pos], pos+1, a-1,b,c,d)
    if b:
        func(res - arr[pos], pos+1, a,b-1,c,d)
    if c:
        func(res * arr[pos], pos+1, a,b,c-1,d)
    if d:
        # tip: 음수 나눗셈 계산 시 몫 구하기 '//' 연산자와 다름.
        func(int(res / arr[pos]), pos+1, a,b,c,d-1)

# solve
func(arr[0], 1, a,b,c,d)
print(mx, mn, sep="\n")