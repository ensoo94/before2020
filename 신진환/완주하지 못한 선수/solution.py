def solution(participant, completion):
    participant_dict = {p:0 for p in participant}
    
    for p, c in zip(participant, completion):
        participant_dict[p] += 1
        if c:
            participant_dict[c] -= 1
        
    return max(participant_dict, key=participant_dict.get)