def solution(max_weight, specs, names):
    answer = 1
    remain_weight = max_weight
    
    # dictionary 이용
    specs = dict(specs)
    
    for product in names:
        weight = int(specs[product])
        if weight > remain_weight:
            answer += 1
            remain_weight = max_weight - weight
        else:
            remain_weight -= weight
    
    return answer