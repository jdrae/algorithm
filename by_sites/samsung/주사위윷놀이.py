# setting
path = [[1],[2],[3],[4],[5],[6,21],[7],[8],[9],[10],[11,27],[12],[13],[14],[15],[16,29],[17],[18],[19],[20],[32], 
        [22],[23],[24],[25],[26],[20], [28],[24], [30],[31],[24], [32]]
score = [0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,13,16,19,25,30,35,22,24,28,27,26,0]

# input
cmd = list(map(int,input().split()))

# backtrack
answer = 0
pawn = [0] * 4
def func(idx, result):
    global answer
    if idx == 10:
        answer = max(answer, result)
        return
    
    for i in range(4):
        x = pawn[i]
        if len(path[x]) == 2: # 파란색칸에서 시작할경우
            x = path[x][1]
        else:
            x = path[x][0]
        for _ in range(1, cmd[idx]): # 위에서 한칸 감
            x = path[x][0]

        if x == 32 or (x not in pawn): # 도착점이거나 칸에 말이 없을 경우
            before = pawn[i]
            pawn[i] = x
            func(idx+1, result+score[x])
            pawn[i] = before

func(0,0)
print(answer)