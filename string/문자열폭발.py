s = input()
bomb = input()

st = []
for c in s:
    st.append(c)
    if c == bomb[-1] and ''.join(st[-len(bomb):]) == bomb:
        # tip: 리스트 중간 원소 삭제
        del st[-len(bomb):]

ans = ''.join(st)
if ans == '':
    print("FRULA")
else:
    print(ans)