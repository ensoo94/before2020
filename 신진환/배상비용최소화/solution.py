def solution(no, works):
    # short circuit
    if sum(works) < no:
        return 0
    
    # Only once iterate all works at the first time.
    works.sort(reverse=True) 
    
    # Differencial calculus.
    prev_work = works[0]
    check_point = 0
    for i, w in enumerate(works):
        check_point = i
        
        tmp = int(no)
        tmp -= i * (prev_work - w)
        if tmp < 0:
            check_point -= 1
            break
        else:
            prev_work = w
            no = tmp
    
    # `last_works` is only using calculating before check point in works array
    # `remain_works` is cumulated after check point in works array
    last_works = prev_work ** 2
    remain_works = sum([w * w for w in works[check_point:]])
    
    # Then will substrate exceed works from `last_works`
    # `works_count` for how many exist as same value as the value in works[check_point]
    exceed_works = 0
    works_count = check_point + 1
    
    chunk_amount = no // works_count
    unit_amount = no % works_count
    
    chunk_works = last_works
    
    for i in range(chunk_amount):
        chunk_works -= 2 * (works[check_point] - i) - 1
    
    exceed_works += (last_works - chunk_works) * works_count
    exceed_works += (2 * (works[check_point] - chunk_amount) - 1 ) * unit_amount
    
    answer = (last_works * check_point) + remain_works - exceed_works
    
    return answer