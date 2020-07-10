# 어떤 케이스던 제일 큰거를 -1씩 해가는게 최소 배상비용임
# => 오름차순으로 sort하고 works[-1]을 -1씩함, no도 -1
# 정답은 sum(i**2 for i in works)

def solution(no, works):
    # 편의를 위해 오름차순으로 정렬  O(nlogn)
    works.sort()
    
    # 시간복잡도는 O(n^2*logn)인가요? 
    while no > 0:
        # 정렬 후 works의 마지막 인덱스가 0 이하면 break O(1)
        if (works[-1] <= 0):
            break
        # 제일 많은 작업량이 남은 선박을 1시간 동안 일하니 works[-1]--, no--
        works[-1] -= 1
        no -= 1
        # 다시 정렬해서 룹 반복
        works.sort()
        
    result = sum(i**2 for i in works)
    
    return result