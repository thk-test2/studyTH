
pado_list = [0, 1, 1, 1, 2, 2]

def pado(N):
    if N < len(pado_list):
        return pado_list[N]
    
    pado_list.append(pado(N-1)+pado(N-5))
    # print(pado_list)
    return pado_list[N]

T = int(input())

for i in range(T):
    N = int(input())
    print(pado(N))

