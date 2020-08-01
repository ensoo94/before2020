def solution(A,B):
    A.sort()
    B.sort()
    
    return sum([a * B.pop() for a in A])