"""
초   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
나무1| 0 | 1 | 1 | 0 | 0 | 1 | 1 |
나무2| 1 | 0 | 0 | 1 | 1 | 0 | 0 |

1. 그리디가 아닌 이유
1초에 2번, 2~3초에 1번, 4초에 2번으로 돌아오면 2번 움직여서 5를 얻는다.
1초에 자두를 못받더라도 1번에 있는게 이득이다.
즉, 자두가 있는 쪽으로 움직이는 탐욕법(그리디)가 아니다.

2. 순수 dfs 가 아닌 이유(메모이제이션이 가능한 이유) -> dp 함수도 dfs 로 볼 수 있음. dfs+메모이제이션 = dp(의 한종류)
7개의 칸 _______ 을 어떤 나무번호로 채워야 최댓값이 될지를 결정하는 방법은 dfs 이다. 
예제에서는 1112211 이 정답 6이 되고, 이는 최댓값을 얻기 위해 지나가는 경로라고 볼 수 있다. (중복순열, 15651 번 참고)
하지만 정답을 얻기 위해 1111111, 1111112, 1111121, 1111122 ... 와 같이 모든 경로를 탐색해야한다.
만약 7초에서의 최댓값이 정해졌다면, 6초에서의 최댓값은 7초에서의 최댓값 + 6초의 값이고,
일반화하여 i 초의 최댓값은 i+1 초의 최댓값을 통해 알 수 있다. 즉, i+1 초의 값을 매번 계산할 필요가 없다.
따라서 메모이제이션을 적용한 dp 문제로 접근한다.
"""

t, w = map(int,input().split())
arr = [int(input()) for _ in range(t)]
TREE_NUM = 2


def recursive_top_down():
    # dp[i][j]: i초에 j번 움직였을 때 얻을 수 있는 최댓값
    dp = [[-1]*(w+1) for _ in range(t)]

    # recursive, top_down
    def func(pos, cnt):
        # basecase
        if pos >= t or cnt > w: return 0

        # memoization
        ret = dp[pos][cnt]
        if ret != -1: return ret

        # 현재 나무 번호 계산
        if cnt%2: tree = 2 # 홀수번 움직이면 2번 나무(1번에서 시작하므로)
        else: tree = 1

        # 현재 얻을 수 있는 자두 추가
        if arr[pos] == tree: ret = 1
        else: ret = 0

        # dp
        move = func(pos+1, cnt+1) # 움직였을 때 
        not_move = func(pos+1, cnt) # 안 움직였을 때
        ret += max(move, not_move)

        dp[pos][cnt] = ret # 꼭 다시 넣기
        return ret

    print(max(func(0,0), func(0,1)))


def tabulation_bottom_up():
    # dp[i][j][k]: i 초에 j-1 번 움직여서 k 번 나무일때 얻을 수 있는 최댓값
    dp = [[[0]*(TREE_NUM+1) for _ in range(w+2)] for __ in range(t)]

    # 초기값(0초일 경우)
    if arr[0] == 1: 
        dp[0][1][1] = 1 # 0번 움직여서 1번 자두
    else: 
        dp[0][2][2] = 1 # 1번 움직여서 2번 자두

    for i in range(1, t):
        for j in range(1,w+2): # [0,w+1) 로 생각
            # i 초에 j 번 움직여서 1번 나무에 있는 경우는
            # i-1 초에 j 번 움직여서 1번 자두를 받았던 값과(안움직임)
            # i-1 초에 j-1 번 움직여서 2번 자두를 받았던 값 비교(움직임)
            # 2번 나무에 있는 경우도 비슷하게 진행
            dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][2])
            dp[i][j][2] = max(dp[i-1][j-1][1], dp[i-1][j][2])

            if arr[i] == 1:
                dp[i][j][1] += 1
            else:
                dp[i][j][2] += 1

    # 최댓값 탐색
    mx = 0
    for j in range(1,w+2):
        # 마지막(t-1초)에 j 번 움직여서 1번/2번 나무에 있는게 최대인지
        mx = max(mx, max(dp[t-1][j][1], dp[t-1][j][2]))
    print(mx)


# 답 출력
print("REC")
recursive_top_down()
print("TAB")
tabulation_bottom_up()
