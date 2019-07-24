

num = int(input())
answer = 0

for i in range(1, num+1):
    coef_num_list = list(map(int, str(i)))
    answer = i + sum(coef_num_list)
    
    if answer == num:
        print(i)
        break

    if i == num:
        print(0)