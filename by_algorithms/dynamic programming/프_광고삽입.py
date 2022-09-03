def tton(time):
    h, m, s = map(int,time[:8].split(":"))
    return h*3600 + m*60 + s

# tip: 숫자를 시간 문자열로
def ntot(num):
    h = '0' + str(num//3600)
    m = '0' + str((num%3600)//60)
    s = '0' + str((num%3600)%60)
    return ":".join([h[-2:], m[-2:], s[-2:]])

def solution(play_time, adv_time, logs):
    answer = ''
    pl, ad = tton(play_time), tton(adv_time)
    dp = [0 for _ in range(pl+1)] 

    # dp[x]: (x 시각에 시작된 log 의 개수) - (x 시각에 종료된 log 의 개수)
    for l in logs:
        s = tton(l[:8])
        e = tton(l[9:])
        dp[s] = dp[s] + 1
        dp[e] = dp[e] - 1

    # dp[x]: 시각 x 부터 x+1 까지 log의 개수
    for i in range(1, pl): 
        dp[i] = dp[i] + dp[i-1]

    # dp[x]: 시각 0 부터 x+1 까지 누적 재생시간
    for i in range(1, pl):
        dp[i] = dp[i] + dp[i-1]

    mx, ans = 0, 0
    at = ad
    for i in range(ad-1, pl):
        if i >= at:
            if mx < dp[i] - dp[i-at]:
                mx = dp[i] - dp[i-at]
                ans = i - at + 1
        else:
            mx = dp[i]
    return ntot(ans)

print(solution("02:03:55",	"00:14:15",	["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"]))
print("01:30:59")
print(solution("99:59:59",	"25:00:00",	["69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"]))
print("01:00:00")