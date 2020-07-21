from collections import Counter

def solution(board, nums):
    answer = 0
    d_arr1 = []
    d_arr2 = []
    
    # 숫자 지우기, 대각행렬 구하기
    for i in range(0, len(board)):
        for j in range(0, len(board)):
            if i == j: # O(nums)
                d_arr1.append(board[i][j])
            if j == len(board)-i-1:
                d_arr2.append(board[i][j])
            if board[i][j] in nums:
                board[i][j] = 0
    
    # 빙고 세기
    for r_line in board: #row
        if r_line == [0]*len(board): # 리스트와 리스트의 비교 : O(n)
            answer += 1
    for c_line in list(zip(*board)): #col
        if list(c_line) == [0]*len(board):
            answer += 1
            
    # 대각선
    if len(Counter(nums) - Counter(d_arr1)) == len(nums) - len(board): # Counter로 만드는 데 O(n)
        answer += 1
    if len(Counter(nums) - Counter(d_arr2)) == len(nums) - len(board):
        answer += 1

    return answer