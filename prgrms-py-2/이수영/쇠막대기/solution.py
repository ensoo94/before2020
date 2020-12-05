def solution(arrangement):
    answer = 0
    
    # 레이저 구분
    # Python의 replace는 원래 str 변화x 결과값을 return하는 함수
    arrangement = arrangement.replace('()', '0')
    
    cnt = 0 # 쇠막대기의 수
    for point in arrangement:
        if point == '(': # 쇠막대기의 수 + 1
            cnt += 1
        elif point == '0': # 현재 쇠막대기의 수만큼 토막 생김
            answer += cnt
        elif point == ')': # 쇠막대기의 마지막 부분
            answer += 1
            cnt -= 1
    
    return answer