def sep(p):
    u, v = '', ''
    op, cl = 0, 0
    for c in p:
        u += c
        if c == ')': cl += 1
        else: op += 1
        if op == cl:
            u = p[:op+cl]
            v = p[op+cl:]
            break
    return u, v

def right(p):
    ret = True
    size = 0
    for c in p:
        if size == 0:
            if c == '(':
                size += 1
            else:
                return False
        else:
            if c == ')':
                size -= 1
            else:
                size += 1
    return ret

def make(v):
    ret = ''
    if v == '': return ''
    u, v = sep(v)
    if right(u):
        ret += u
        ret += make(v)
    else:
        new = '('
        new += make(v)
        new += ')'
        for i in range(1, len(u)-1):
            if u[i] == '(': new += ')'
            else: new += '('
        ret = new
    return ret

def solution(p):
    answer = make(p)
    return answer

print(solution("()))((()"))
print("()(())()")
print(solution(")("))
print("()")