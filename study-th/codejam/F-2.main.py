# 오답

T = int(input())

for i in range(T):

    n, m, k = map(int, input().split())

    oStr = input()
    oList = list(oStr[:])

    for j in range(m):
        x, y = map(int, input().split())
        sList = oList[x-1:y]
        sBinary = "".join(sList)
        mask = '1'*(y-x+1)

        sBinary = int(mask, 2) - int(sBinary, 2)
        sBinary = "{0:b}".format(sBinary)
        # print(sBinary)
        # print(sList[0], mask[2])
        if x!=y and sList[0]=='1':
            sBinary = '0'+sBinary
        # print(type(sBinary), sBinary)
        oList = oList[:y] + list(sBinary) + oList[y:]
    print("".join(oList[:k]))