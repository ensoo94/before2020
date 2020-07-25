def solution(s):
    answer = []
    s = list(s)
    
    # stack 사용
    for letter in s:
        while len(answer) > 0 and answer[-1] < letter:
            answer.pop()
        answer.append(letter)
        
    answer = ''.join(answer)

    return answer