from math import ceil

def solution(progresses, speeds):
    answer = []

    #배포일 check
    release_date = [] # Python은 snake_case 변수명 선호
    for i in range(0, len(speeds)):
        remainJob = ceil((100 - progresses[0]) / speeds[0]) # 필요없는 조건문 없애고 올림
        release_date.append(remain_job)
    
    #순서대로 배포
    while len(release_date) > 0 :
        cnt = 0
        for date in release_date:
            if date > release_date[0] :
                break
            cnt += 1
        answer.append(cnt)
        release_date = release_date[cnt:]
        
    return answer  