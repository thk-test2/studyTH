#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void setupMatrix(int** cost, int n)
{
    char temp[100];
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            scanf("%s", temp);
            if (temp[0] == 'x')
                cost[i][j] = 0;
            cost[i][j] = atoi(temp);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cost[i][j] = cost[j][i];
            if (cost[i][j] == 0) {
                cost[i][j] = INT_MAX;
            }
        }
    }
}

void printMatrix(int** cost, int n)
{
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
}

int find(int *parent, int i)
{
    while (parent[i]) {
        i = parent[i];
        break;
    }
    return i;
}

int unionParent(int * parent, int i,int j)
{
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int minCost(int** cost, int* parentSet, int n)
{
    int min, result = 0;
    int i, j;
    int a, b, parentI, parentJ;
    int traveledNode = 1;

    while (traveledNode < n) {
        for(i=0, min=INT_MAX; i<n; i++) {
            for(j=0; j<n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = parentI = i;
                    b = parentJ = j;
                }
            }
        }
        parentI = find(parentSet, parentI);
        parentJ = find(parentSet, parentJ);
        if (unionParent(parentSet, parentI, parentJ)) {
            result += min;
            traveledNode++;
        }
        cost[a][b] = cost[b][a] = INT_MAX;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);

    int** cost;
    cost = (int**) malloc (sizeof(int*) * n);
    for (int i=0; i<n; i++)
        cost[i] = (int*) malloc(sizeof(int) * n);
    int* parentSet = (int*) malloc(sizeof(int) * n);

    setupMatrix(cost, n);
//    printMatrix(cost, n);
    printf("%d\n", minCost(cost, parentSet, n));

    free(parentSet);
    for (int i=0; i<n; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
