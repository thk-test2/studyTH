
def fac(n):
    if (n==0 or n==1):
        return 1
    return n*fac(n-1)

n = int(input())
result = fac(n)
print(result)