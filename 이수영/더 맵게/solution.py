import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    
    while len(scoville) > 0:
        low_food = heapq.heappop(scoville)
        if low_food >= K:
            return answer
            
        # if ~ else 말고 try ~ except로 예외처리
        try:
            second_food = heapq.heappop(scoville)
            answer += 1
            new_food = low_food + (second_food*2)
            heapq.heappush(scoville, new_food)
        except: 
            return -1             

    return answer