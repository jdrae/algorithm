def solution(distance, rocks, n):
    answer = 0
    rocks.sort()
    lo = 0
    hi = distance
    
    while lo + 1 < hi:
        prev, cnt = 0, 0
        mid = (int)((lo+hi)/2)
        for r in rocks:
            if r - prev < mid:
                cnt+=1
            else:
                prev = r
        if distance - prev < mid:
            cnt += 1
        
        if cnt > n:
            hi = mid
        else:
            lo = mid
    answer = lo
    return answer