def solution(no, works):
    result = 0
    #가장 큰 수 찾아서 깎기
    while no > 0 :
        works.sort()
        if works[-1] <= 0 :
            break
        works[-1]-=1
        no-=1
    
    result = sum([i**2 for i in works])
    return result