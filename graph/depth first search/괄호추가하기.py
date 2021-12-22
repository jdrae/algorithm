n = int(input())
arr = input()

mx = -3000000000
def func(idx, cur):
    global mx
    if idx >= n:
        mx = max(mx, cur)
        return
    op = '+' if idx == 0 else arr[idx-1]

    if idx+2 < n:
        bracket = cal(int(arr[idx]), int(arr[idx+2]), arr[idx+1])
        func(idx+4, cal(cur, bracket, op))
    func(idx+2, cal(cur, int(arr[idx]), op))

def cal(a, b, op):
    if op == "+":
        return a+b
    if op == "-":
        return a-b
    if op == "*":
        return a*b

func(0,0)
print(mx)