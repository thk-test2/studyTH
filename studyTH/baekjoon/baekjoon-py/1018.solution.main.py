
def checkBoard(Field, Board, dx, dy):
    count = 0
    for i in range(8):
        for j in range(8):
            if Field[dx+i][dy+j] != Board[i][j]:
                count += 1
    return count

def solution():
    whiteBoard = [
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']
    ]

    blackBoard = [
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']
    ]

    M, N= map(int, input().split(' '))
    Field = [[0] * N for i in range(M)]

    for i in range(M):
        Board = input()
        for j in range(N):
            Field[i][j] = Board[j]


    result = 1048576

    for i in range(0, M-7):
        for j in range(0, N-7):
            w = checkBoard(Field, whiteBoard, i, j)
            b = checkBoard(Field, blackBoard, i, j)

            result = min(result, w, b)
    print(result)

solution()