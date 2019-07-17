def powerset(s): #배열생성이 generate 방식이다
    x = len(s)
    masks = [1 << i for i in range(x)]
    # print(masks)
    for i in range(1, 1 << x):
        print([(ss,mask) for mask, ss in zip(masks, s) if i & mask])
        yield [ss for mask, ss in zip(masks, s) if i & mask]

n, s = map(int, input().split())
setA = powerset(list(map(int, input().split())))
cnt = 0
for i in setA:
    if sum(i) == s:
        cnt += 1

print(cnt)

print([i for i in range(10) if i & 2])