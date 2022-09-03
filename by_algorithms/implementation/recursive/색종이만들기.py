n = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]
w, b = 0,0

def func(y,x,size):
    global w, b
    if size == 1:
        if arr[y][x]: b += 1
        else: w += 1
        return
    divide = False
    color = arr[y][x]
    for i in range(y,y+size):
        for j in range(x,x+size):
            if color != arr[i][j]:
                divide = True
                break
        if divide: break
    if divide:
        size //= 2
        func(y,x,size)
        func(y+size, x, size)
        func(y,x+size,size)
        func(y+size,x+size,size)
    else:
        if color: b += 1
        else: w += 1

func(0,0,n)
print(w)
print(b)