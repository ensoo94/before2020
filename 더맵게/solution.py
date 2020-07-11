import heapq

def solution(scoville, K):
    answer = 0
    
    while scoville[0] < K:
        # 모든 음식의 다섞어도(len(scoville) ==1) 스코빌지수가 K미만일시 -1 리턴  O(1)
        if len(scoville) == 1 and scoville[0] < K:
            return -1      
        
        # heapq써서 젤작은거 2개 팝하고 섞은음식을 푸시함  O(logn)
        heapq.heappush(scoville, (heapq.heappop(scoville) + heapq.heappop(scoville) * 2))
        # 빼고 섞었으니 answer++  O(1)
        answer += 1
        # 푸시되서 정렬안된 스코빌 리스트를 다시 힙으로 변환 O(n)
        heapq.heapify(scoville)
        
    return answer