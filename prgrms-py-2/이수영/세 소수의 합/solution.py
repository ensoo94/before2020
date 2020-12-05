def solution(n):
    answer = 0
    
    #소수 문제 = 에라토스테네스의 체?
    p_num = [0] * 1000
    for i in range(2, 1000):
        p_num[i] = i

    for j in range(len(p_num)):
        if p_num[j] == 0:
            continue
        else:
            for num in range(j * 2, len(p_num), j):
                p_num[num] = 0

    prime_number = [i for i in p_num if i != 0]
    
    result = 0
    for f_idx in range(len(prime_number)):
        for s_idx in range(f_idx + 1, len(prime_number)):
            for t_idx in range(s_idx + 1, len(prime_number)):
              result = prime_number[f_idx] + prime_number[s_idx]
              result += prime_number[t_idx]
              if result == n:
                  answer += 1          

    return answer