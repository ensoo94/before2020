def solution(progresses, speeds):
    answer = []

    #배포일 check
    releaseDate = []
    for i in range(0, len(speeds)):
        #python은 int/int 해도 결과값이 소수!
        remainJob = int((100 - progresses[i])/speeds[i])
        if (100 - progresses[i])%speeds[i] != 0:
            remainJob += 1
        releaseDate.append(remainJob)
    
    #순서대로 배포
    while len(releaseDate) > 0 :
        cnt = 0
        for date in releaseDate:
            if date > releaseDate[0] :
                break
            cnt += 1
        answer.append(cnt)
        releaseDate = releaseDate[cnt:]
        
    return answer                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          