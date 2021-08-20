from collections import deque

def solution(command, lst):
    command = deque(command)
    lst = deque(lst)
    ptr = 0
    while len(command) != 0:
        c = command.popleft()
        if c == "R":
            ptr = (1 if ptr == 0 else 0)
        elif c == "D":
            if not lst:
                return "error"
            if ptr: lst.pop()
            else: lst.popleft()
    
    if ptr: lst.reverse() # tip: lst[::-1]
    return str(list(lst)).replace(" ","")

if __name__ == "__main__":
    t = int(input())
    while(t > 0):
        t -= 1
        p = list(input())
        n = int(input())
        lst = input()[1:-1]
        if len(lst):
            lst = list(map(int, lst.split(',')))
        else:
            lst = []
        
        print(solution(p, lst))