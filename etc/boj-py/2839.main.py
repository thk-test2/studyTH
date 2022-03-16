inp = int(input())
Box = 0
while True:
    if (inp % 5) == 0:
        Box = Box + (inp//5)
        print(Box)
        break
    inp = inp-3
    Box += 1
    if inp < 0:
        print("-1")
        break