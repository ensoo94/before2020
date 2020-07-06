def solution(skill, skill_trees):
    answer = 0
    
    for tree in skill_trees:
        count = 0
        for s in skill:
            if s in tree:
                count += 1
                
        if skill[:count] == "".join([t for t in tree if t in skill]):
            answer += 1
                
    return answer