import heapq
def solution(no, works):
    result = 0
    works = [-j for j in works] # max_heap
    heapq.heapify(works)
    
    # 남은 일의 합 < no면 무조건 0
    if -sum(works) <= no :
        return 0
    
    # 가장 큰 수 찾아서 깎기
    while no > 0:
        work = heapq.heappop(works) + 1
        heapq.heappush(works, work)
        no -= 1
       
    result = sum([i**2 for i in works])
    return result