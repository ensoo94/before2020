def solution(s):
    s = list(s)
    answer = []
    
    for letter in s:
        if len(answer) > 0 and answer[-1] == letter:
            answer.pop()
        else:
            answer.append(letter)

    return int(answer == [])