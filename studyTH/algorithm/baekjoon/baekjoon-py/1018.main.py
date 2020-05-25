
import copy

N, M = map(int, input().split())
chess = []

for i in range(N):
    chess.append(list(input()))

# print(N, M)
# print(chess)
count_list = []
count = 0
original_chess = copy.deepcopy(chess) 
for k in range(0, N-8+1):
    for l in range(0, M-8+1):
        for i in range(k, k+8):
            for j in range(l, l+7):
                # print(i, j)
                # print(k, l)
                # count = count + 1
                # print(chess[i][j], count)
                # 조건문 구성 필요
                if j == l and i > k:
                    if chess[i][j] == chess[i-1][j]:
                        if chess[i][j] == 'B':
                            chess[i][j] = 'W'
                            # print(chess[i][j], chess[i-1][j], i, j)
                            count = count+1
                        else :
                            chess[i][j] = 'B'
                            count = count+1

                if chess[i][j] == chess[i][j+1]:
                    if chess[i][j] == 'B':
                        chess[i][j+1] = 'W'
                        count = count+1
                    else :
                        chess[i][j+1] = 'B'
                        count = count+1
        count_list.append(count)
        count = 0
        print(chess)
        chess = copy.deepcopy(original_chess)
        j=j+1
    i=i+1

count_list.sort()
# print(count_list)
print(count_list[0])
# print(chess)
# print(original_chess)