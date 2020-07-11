import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    
    while len(scoville) > 0 :
        lowFood = heapq.heappop(scoville)
        if lowFood >= K : #가장 낮은 값이 K보다 클 때
            return answer
        elif len(scoville) == 0: #다 섞었는데 K보다 작을 때
            return -1
        else:
            answer += 1
            secondFood = heapq.heappop(scoville)
            newFood = lowFood + (secondFood*2)
            heapq.heappush(scoville, newFood)

    return answer