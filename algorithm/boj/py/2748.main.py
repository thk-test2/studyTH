
fibo_list=[0, 1,]

def fibo(N):
    if N < len(fibo_list):
        return fibo_list[N]
    
    fibo_list.append(fibo(N-1)+fibo(N-2))
    # print(N, fibo_list)

    return fibo_list[N]

N = int(input())

print(fibo(N))

