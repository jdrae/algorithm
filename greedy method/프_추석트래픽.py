def solution(lines):
    answer = 0
    log = []
    for l in lines:
        _, s, t = l.split()
        dur = int(float(t.replace('s','')) * 1000)
        nl = s.split(":")
        end = int(nl[0]) * 60 * 60 * 1000 + int(nl[1]) * 60 * 1000 + int(float(nl[2]) * 1000)
        start = end - dur + 1
        log.append([start, end])

    for l in log:
        scnt, ecnt = 0, 0 # 로그의 시작과 끝의 1초만 비교
        s, s_1 = l[0], l[0] + 1000
        e, e_1 = l[1], l[1] + 1000
        for m in log:
            if s <= m[1] and m[0] < s_1: # 겹침: 끝이 기준시작보다 이후, 시작이 기준끝보다 이전
                scnt+=1
            if e <= m[1] and m[0] < e_1:
                ecnt+=1
            answer = max(answer, scnt, ecnt)
            
    return answer

print(solution(["2016-09-15 01:00:04.001 2.0s","2016-09-15 01:00:07.000 2s"]))
print(1)
# print(solution(["2016-09-15 01:00:04.002 2.0s","2016-09-15 01:00:07.000 2s"]))
# print(2)