def solution(s):
    answer = True
    
    if s[0] == ")" or s[-1] == "(":
        return False
    
    stack = [True]
    for i, j in enumerate(s[1:]):
        # Short circuit
        if len(stack) == 0 and j == ")":
            return False
        if j == "(":
            stack.append(True)
        if j == ")":
            stack.pop()
    
    return len(stack) == 0