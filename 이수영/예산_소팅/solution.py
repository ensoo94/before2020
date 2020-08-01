def solution(d, budget):
    answer = 0
    
    d.sort()
    for rq in d:
        if rq <= budget:
            budget -= rq
            answer += 1
        else:
            break
            
    return answer