
N = int(input())

words = []
for i in range(N):
    word = input()
    words.append( (len(word), word) )

words = list(set(words))
words.sort(key=lambda tup:(tup[0], tup[1]))    

for i in words:
    print(i[1])
    