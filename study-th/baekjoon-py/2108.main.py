

# Time Over

N = int(input())
numbers = []
for i in range(N):
    numbers.append(int(input()))

print(sum(numbers)//N)
numbers.sort()
print(numbers[len(numbers)//2])

count = []
for i in numbers:
    count.append((numbers.count(i), i))

# print(count)
ex_count = list(set(count))
ex_count.sort(key=lambda tup:tup[1])
# print(ex_count)
max_value = max(ex_count, key=lambda tup:tup[0])
# print(max_value)

same_max_values=[]
for i in count:
    if max_value[0] == i[0]:
        same_max_values.append(i)
same_max_values = list(set(same_max_values))

if len(same_max_values) > 1:
    print(same_max_values[1][1])
else:
    print(same_max_values[0][1])

print(numbers[len(numbers)-1]-numbers[0])
