
count = int(input())
people = list()

for i in range(count):
    a, b = map(int, input().split())
    people.insert(i, (a, b))

for c in people :
    rank = 1

    for n in people:
        if (c[0]!=n[0] & (c[1]!=n[1])):
            if (c[0]<n[0] & (c[1]<n[1])):
                rank += 1
    print(rank)