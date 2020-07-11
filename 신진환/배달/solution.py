from queue import PriorityQueue

def solution(N, road, K):
    
    pq = PriorityQueue()
    pq.put((0, 1)) # append No.1 as start point.
    
    dist_list = [float('inf')] * (N + 1)
    dist_list[1] = 0
    
    while not pq.empty():
        dist, src = pq.get()
        for r in road:
            new_dist = dist + r[2]
            
            if r[0] == src and new_dist < dist_list[r[1]]:
                dist_list[r[1]] = new_dist
                pq.put((new_dist, r[1]))
            if r[1] == src and new_dist < dist_list[r[0]]:
                dist_list[r[0]] = new_dist
                pq.put((new_dist, r[0]))
    
    return len([t for t in dist_list if t <= K])