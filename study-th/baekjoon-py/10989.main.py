
#입력될 수 있는 숫자의 최대 크기를 의미합니다. 
MAX_NUM = 10000000

#A는 입력된 숫자를 저장하는 배열
A = list(map(int, input().split())) 

#N은 입력된 숫자의 개수 입니다.
N = len(A)

#0으로 초기화된 입력될 MAX_NUM+1 길이의 배열 count를 생성합니다.
count =[0]*(MAX_NUM+1) 
#countSum은 누적합을 저장하는 배열입니다. 
countSum =[0]*(MAX_NUM+1) 

#숫자 등장 횟수 세기 
for i in range(0, N): 
    count[A[i]] += 1 
    
#숫자 등장 횟수 누적합 구하기
countSum[0] = count[0]
for i in range(1, MAX_NUM+1):
    countSum[i] = countSum[i-1]+count[i]
    
#B는 정렬된 결과를 저장하는 배열
B = [0]*(N+1)

for i in range(N-1, -1, -1):
    B[countSum[A[i]]] = A[i] 
    countSum[A[i]] -= 1 

#수열 A를 정렬한 결과인 수열 B를 출력한다.
#result = ""
for i in B:
    print(i)
#    result += str(B[i]) + " "
    
#print(result)

