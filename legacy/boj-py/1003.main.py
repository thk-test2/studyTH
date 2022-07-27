
fibo_list=[0, 1,]

def fibo(N):
    if N < len(fibo_list):
        return fibo_list[N]
    
    fibo_list.append(fibo(N-1)+fibo(N-2))
    # print(N, fibo_list)

    return fibo_list[N]

N = int(input())

cnt_list = []
for i in range(N):
    n = int(input())

    if n == 0:
        cnt_list.append( (1, 0) )
    elif n == 1:
        cnt_list.append( (0, 1) )
    else: 
        cnt_list.append( (fibo(n-1), fibo(n)) )

for i in cnt_list:
    print(str(i[0])+" "+str(i[1]))
