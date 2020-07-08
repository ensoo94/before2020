def solution(N, road, K):
    start_point = 1
    shortest_length = { l:10000*N for l in range(1, N+1)}
    shortest_length[start_point] = 0
    
    queue = [n for n in range(1, N+1)]
    
    while queue:
        for r in road:
            updated_length = shortest_length[start_point] + r[2]
            if r[0] == start_point:
                shortest_length[r[1]] = min(updated_length, shortest_length[r[1]])
            if r[1] == start_point:
                shortest_length[r[0]] = min(updated_length, shortest_length[r[0]])

        queue.remove(start_point)
        
        # Select Next Starting point
        tmp = 10000*N
        for q in queue:
            if tmp > shortest_length[q]:
                tmp = shortest_length[q]
                start_point = q

        if tmp == 10000*N:
            break
        
    return len([i for i, v in shortest_length.items() if v <= K])