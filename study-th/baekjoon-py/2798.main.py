
from itertools import combinations

N, M = map(int, input().split())
cards = [int(x) for x in input().split()]

cards.sort()
cards_group = list(combinations(cards, 3))

res = [sum(x) for x in cards_group]

close_sum = res[0]
for i in res:
    if close_sum < i <= M:
        close_sum = i

if close_sum > M:
    exit()
print(close_sum)