
A = int(input())
B = int(input())
C = int(input())

D = str(A*B*C)
a = list(D)
b = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

a = list(map(int, a))

for i in b:
    print(a.count(i))