numbers = []
max_num = 0
idx = 0

for i in range(9):
    number = int(input())
    numbers.append(number)
    max_num = max(numbers) 
    if max_num == number:
        idx = i + 1

print(max_num)
print(idx)