# 집합1 부분 성공

T = int(input())

for i in range(T):

    n, m, k = map(int, input().split())

    oStr = input()
    oList = list(oStr[:])

    for j in range(m):
        x, y = map(int, input().split())
        sList = oList[x-1:y]

        for i in range(len(sList)):
            if sList[i] == '0':
                sList[i] = '1'
            else:
                sList[i] = '0'

        # print(sList)
        oList = oList[:y] + sList + oList[y:]
        #print(oList)
    print("".join(oList[:k]))