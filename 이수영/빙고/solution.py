def solution(board, nums):
    N = len(board)
    answer = 0
    nums = dict.fromkeys(nums, True)
    row_list = [0] * N
    col_list = [0] * N
    left_diagonal = 0
    right_diagonal = 0

    
    # 숫자 지우기, 대각행렬 구하기
    for i in range(N):
        for j in range(N):
            if board[i][j] in nums:
                board[i][j] = 0
                row_list[i] += 1
                col_list[j] += 1

                if i == j: 
                    left_diagonal += 1
                if j == N-i-1:
                    right_diagonal += 1
    
    # 빙고 세기
    answer += sum([1 for i in row_list if i == N])
    answer += sum([1 for i in col_list if i == N])
    answer += 1 if left_diagonal == N else 0
    answer += 1 if right_diagonal == N else 0

    return answer