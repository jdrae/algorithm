START, END = 0, 1
def solution(lines):
    answer = 0
    log = []
    for l in lines:
        _, s, t = l.split()
        dur = int(float(t.replace('s','')) * 1000)
        nl = s.split(":")
        end = int(nl[0]) * 60 * 60 * 1000 + int(nl[1]) * 60 * 1000 + int(float(nl[2]) * 1000)
        start = end - dur + 1
        log.append([start, START])
        log.append([end+999, END]) # 끝나는 지점 포함 999 ms 이후에 START 있으면, START 먼저 나와서 cnt++

    # tip: 파이썬 두개 기준 정렬
    log.sort(key = lambda x: (x[0], x[1])) # 시간 순 정렬 후, 같을 시 START 먼저 정렬.

    cnt = 0
    for l in log:
        if l[1] == START: cnt += 1
        else: cnt -= 1
        answer = max(answer, cnt)
    return answer

print(solution(["2016-09-15 01:00:04.001 2.0s","2016-09-15 01:00:07.000 2s"]))
print(1)
print(solution(["2016-09-15 01:00:04.002 2.0s","2016-09-15 01:00:07.000 2s"]))
print(2)