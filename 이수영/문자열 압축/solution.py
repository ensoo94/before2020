def solution(s):
    answer = 1000
    max_len = len(s)//2
    
    if len(s) == 1 :
        return 1
    
    for i in range(1, max_len+1):
        sliced_list = [s[j:j+i] for j in range(0, len(s), i)] # 일정길이로 자르기
        sliced_list.append('') # 마지막 값 처리를 위해 공백 추가
        cnt = 1 # 반복횟수
        first_str = sliced_list[0]
        result = '' # 압축결과
        
        for s_str in sliced_list[1:] :
            if s_str == first_str :
                cnt += 1
            else :
                if cnt > 1:
                    result += str(cnt)
                result += first_str
                first_str = s_str
                cnt = 1
                
        if len(result) < answer:
            answer = len(result)
                       
    return answer