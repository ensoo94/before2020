def solution(s):
    answer = []
    s = list(s)
    
    # 효율성 통과 못 하는 풀이
    ''' 
    while len(s) > 0:
        idx = s.index(max(s))
        answer.append(s[idx])
        s = s[idx+1:]
    '''
    
    # stack 사용
    for letter in s:
        while len(answer) > 0 and answer[-1] < letter:
            answer.pop()
        answer.append(letter)
        
    answer = ''.join(answer)

    return answer