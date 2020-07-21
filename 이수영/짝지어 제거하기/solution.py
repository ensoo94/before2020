def solution(s):
    s = list(s)
    a_list = []
    b_str = s[0]
    
    while len(s) > 1:
        letter = s.pop(-1)
        if b_str != letter:
            a_list.append(b_str)
            b_str = letter
        else:
            try:
                b_str = a_list.pop()
            except:
                b_str = s.pop(-1) 

    
    return 0 if len(a_list) > 0 else 1