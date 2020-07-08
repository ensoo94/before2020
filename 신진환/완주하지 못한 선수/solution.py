def solution(participant, completion):
    participant_dict = {p:0 for p in participant}
    completion.append(None)
    
    for p, c in zip(participant, completion):
        participant_dict[p] += 1
        if c:
            participant_dict[c] -= 1
        
    return sorted(participant_dict, key=participant_dict.__getitem__)[-1]