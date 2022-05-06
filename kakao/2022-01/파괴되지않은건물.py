"""
(1,2)~(3,4) 까지 N 의 변화를 하고 싶다면
위아래 행에 1차원 배열의 누적합 공식을 적용하고
좌우 열에 1차원 배열의 누적합 공식을 적용한다. 
0 0 0 0 0 0
0 0 N X X -N
0 0 X X X 0
0 0 X X X 0
0 0 -N 0 0 N
"""

def solution(board, skill):
    answer = 0 # 파괴되지 않은 건물 수
    n, m = len(board), len(board[0])
    tmp = [[0]*(m+1) for _ in range(n+1)] # 2차원 누적합 배열

    for type, r1,c1, r2,c2, degree in skill:
        if type == 1: degree = -degree
        tmp[r1][c1] += degree
        tmp[r1][c2+1] -= degree
        tmp[r2+1][c1] -= degree
        tmp[r2+1][c2+1] += degree

    # 행
    for i in range(n):
        for j in range(m):
            tmp[i][j+1] += tmp[i][j]

    # 열
    for j in range(m):
        for i in range(n):
            tmp[i+1][j] += tmp[i][j]

    for i in range(n):
        for j in range(m):
            board[i][j] += tmp[i][j]
            if board[i][j] > 0:
                answer += 1

    for bo in board:
        print(bo)
    return answer


print(solution([[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5]],[[1,0,0,3,4,4],[1,2,0,2,3,2],[2,1,0,3,1,2],[1,0,1,3,3,1]]), 10)
