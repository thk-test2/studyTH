

N = int(input())
# 6661, 6662, 6663,
# print(str(N-1) + '666')

movie = []
count = 0
i = 0
# for i in range(100000):
#   movie.append(str(i))

while True:
    i = i+1
    if '666' in str(i):
        count = count+1

        if count == N or count > 10000:
            print(i)
            break

