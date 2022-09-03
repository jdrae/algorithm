# solve again
def solution(routes):
    answer = 1
    routes.sort()
    print(routes)
    end = routes[0][1]
    for r in routes:
        if r[0] > end:
            answer += 1
            end = r[1]
        if r[1] < end:
            end = r[1]
    return answer