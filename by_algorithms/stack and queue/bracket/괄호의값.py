from collections import deque

is_open = {"(":True, ")":False, "[":True, "]": False}
pair = {"(":")", ")":"(", "[":"]","]":"["}
value = {")":2, "]":3}

arr = input().strip() # 1~30
st= deque([])
cal = deque([])
res = 0
for i, b in enumerate(arr):
    if is_open[b]:
        st.append((b,i))
    else:
        if not st:
            res = 0
            break
        else:
            comp, prev_i = st.pop()
            if comp == pair[b]:
                if prev_i + 1 == i:
                    cal.append((value[b], i))
                else:
                    if not cal:
                        res = 0
                        break
                    val, inner_i = cal[-1]
                    tmp = 0
                    while inner_i > prev_i:
                        cal.pop()
                        tmp += val
                        if cal: val, inner_i = cal[-1]
                        else: break
                    cal.append((value[b]*tmp, i))
            else:
                res = 0
                break

    if i == len(arr) - 1:
        while cal:
            val, i = cal.pop()
            res += val
if st:
    res = 0
print(res)

