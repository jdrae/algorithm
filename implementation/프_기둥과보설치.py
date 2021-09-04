G, B, E, P = 0, 1, 8, 4
def possible(res):
    for x, y, a in res:
        if a == G:
            if y == 0: pass
            elif (x,y-1,G) in res: pass
            elif (x-1,y,B) in res: pass
            elif (x,y,B) in res: pass
            else:
                return False
        else:
            if (x,y-1,G) in res: pass
            elif (x+1,y-1,G) in res: pass
            elif (x-1,y,B) in res and (x+1,y,B) in res: pass
            else:
                return False
    return True


def solution(n, build_frame):
    answer = []
    res = set()
    for x, y, a, b in build_frame:
        item = (x,y,a)
        if b:
            res.add(item)
            if not possible(res):
                res.remove(item)
        elif item in res:
            res.remove(item)
            if not possible(res):
                res.add(item)
    answer = map(list, res)
    return sorted(answer, key=lambda x: (x[0],x[1],x[2]))

print(solution(5,[[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]]))
print([[1,0,0],[1,1,1],[2,1,0],[2,2,1],[3,2,1],[4,2,1],[5,0,0],[5,1,0]])
print(solution(5, [[0,0,0,1],[2,0,0,1],[4,0,0,1],[0,1,1,1],[1,1,1,1],[2,1,1,1],[3,1,1,1],[2,0,0,0],[1,1,1,0],[2,2,0,1]]))
print([[0,0,0],[0,1,1],[1,1,1],[2,1,1],[3,1,1],[4,0,0]])