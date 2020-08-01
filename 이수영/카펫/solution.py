def solution(brown, red):
    answer = []

    len_red = (brown - 4) / 2
    for i in range(1, red + 1):
        if i * (len_red - i) == red:
            answer.append(len_red - i + 2)
            answer.append(i + 2)
            break
    return answer