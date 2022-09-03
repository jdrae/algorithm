from itertools import permutations
from collections import deque
def solution(expression):
    answer = 0
    # to list
    exp, op, tmp = [], [], ''
    for e in expression:
        if e >= '0':
            tmp += e
        else:
            exp.append(int(tmp))
            exp.append(e)
            tmp = ''
            if e not in op: op.append(e)
    exp.append(int(tmp))

    # permutation
    for p in permutations(op, len(op)):
        # change
        post = deque([])
        st = deque([])
        for e in exp:
            if e not in op:
                post.append(e)
            # 우선순위가 같거나 클때 st 에서 pop
            else:
                if e == p[0]: # 높
                    while st and (st[-1] == p[0]):
                        post.append(st.pop())
                elif e == p[1]:
                    while st and (st[-1] == p[1] or st[-1] == p[0]):
                        post.append(st.pop())
                else: # 낮
                    while st: # st 에 있는게 무조건 같거나 큼
                        post.append(st.pop())
                st.append(e)
        while st:
            post.append(st.pop())

        # calculate
        for e in post:
            if e not in op:
                st.append(e)
            else:
                n2 = st.pop()
                n1 = st.pop()
                if e == '+':
                    st.append(n1+n2)
                elif e == '-':
                    st.append(n1-n2)
                elif e == '*':
                    st.append(n1*n2)
        answer = max(answer, abs(st.pop()))
    return answer

print(solution("100-200*300-500+20"),	60420)
