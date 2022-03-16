
## 틀렸다고 나옴

N = int(input())

words = []
for i in range(N):
    a, b = input().split()
    word = (a,b)
    words.append(word)

sorted_words = sorted(words, key=lambda tup:tup[0])
for i in sorted_words:
    print(i[0]+" "+i[1])

