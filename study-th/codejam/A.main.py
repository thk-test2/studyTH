import copy

# Function to rotate a matrix 
def rotateMatrix(n, o_mat): 
    if not len(o_mat): 
        return
    # t_mat = [[0]*n for y in range(n)]
    t_mat = copy.deepcopy(o_mat)

    for i, j in zip(range(n), range(n)):
        t_mat[i][(n+1)//2-1] = o_mat[i][j]
        t_mat[i][n-j-1] = o_mat[i][(n+1)//2-1]
        t_mat[(n+1)//2-1][n-j-1] = o_mat[i][n-j-1]
        t_mat[i][j] = o_mat[(n+1)//2-1][j]
  
    return t_mat 

# Utility Function 
def printMatrix(n, mat):
    for i in range(n):
        for j in range(n):
            print(mat[i][j], end="")
            print(" ", end="")
        print()

def cal_rotate(n, degree): 
    if (degree == 0 or degree == 360 or n==1):
        return 0

    if (degree >= 0) :
        return degree // 45
    else :
        return (360 + degree) // 45

num_test = int(input())

for i in range(num_test):

    n, degree = map(int, input().split())
    aList = [[int(x) for x in input().split()] for y in range(n)]

    rotate_num = cal_rotate(n, degree)

    for i in range(rotate_num):
        aList = rotateMatrix(n, aList)

    printMatrix(n, aList)
