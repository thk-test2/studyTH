

N = int(input())
numbers = []
for i in range(N):
    a = [int(x) for x in input().split()]
    numbers.append(a)

# print(numbers)

numbers.sort(key=lambda tup:(tup[1], tup[0]))
# numbers.sort()

for i in numbers:
    print(str(i[0]) + " " + str(i[1]))