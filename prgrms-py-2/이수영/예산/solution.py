def solution(budgets, M):
    answer = 0

    #모두 더한 값 <= M이면 max가 상한액
    if sum(budgets) <= M:
        answer = max(budgets)
    else:
        #평균값에서 줄여가며 계산
        average = sum(budgets) // len(budgets)
        for _ in range(average):
            tmp_cost = M
            for cost in budgets:
                if cost <= average:
                    tmp_cost -= cost
                else:
                    tmp_cost -= average

            if tmp_cost >= 0:
                answer = average
                break
            else:
                average -= 1
                
    return answer