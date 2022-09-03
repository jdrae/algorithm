# 중복조합
# 뽑힌 숫자 내의 구성에서 같은 숫자가 있을 수 있음.
# (1,1) (1,2) (1,3) (2,2) (2,3) (3,3)

n, m = map(int,input().split())

ans = [0] *m
def func(cnt):
    if cnt == m:
        print(*ans,sep=" ")
        return

    for i in range(1,n+1):
        if cnt > 0 and ans[cnt-1] > i: continue
        ans[cnt] = i
        func(cnt+1)

func(0)