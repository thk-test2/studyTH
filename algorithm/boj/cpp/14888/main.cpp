#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int g_r = -1000000000;
int l_r = 1000000000;

int g = -1000000000;
int l = 1000000000;

void solution_recursive(vector<int>& A, int n, int idx, int sum, int P, int M, int MT, int D) {
    if (idx == n) {
        g_r = max(g_r, sum);
        l_r = min(l_r, sum);
    }
    if (P > 0)
        solution_recursive(A, n, idx+1, sum + A[idx], P-1, M, MT, D);
    if (M > 0)
        solution_recursive(A, n, idx+1, sum - A[idx], P, M-1, MT, D);
    if (MT > 0)
        solution_recursive(A, n, idx+1, sum * A[idx], P, M, MT-1, D);
    if (D > 0)
        solution_recursive(A, n, idx+1, sum / A[idx], P, M, MT, D-1);
}

void solution(vector<int>& A, vector<char>& operators) {
    sort(begin(operators), end(operators));
    do {
        int cal = A[0];
        for (int i = 1; i < A.size(); i++) {
            if (operators[i-1] == '+')
                cal += A[i];
            else if (operators[i-1] == '-')
                cal -= A[i];
            else if (operators[i-1] == '*')
                cal *= A[i];
            else if (operators[i-1] == '/')
                cal /= A[i];
        }
        g = max(g, cal);
        l = min(l, cal);
    } while (next_permutation(begin(operators), end(operators)));
    cout << g << endl << l << endl;
}

int main()
{
    int N, n;
    cin >> N;
    vector<int> A;

    for (int i = 0; i < N; i++) {
        cin >> n;
        A.push_back(n);
    }
    vector<char> operators;

    int P, M, MT, D;
    cin >> P;
    for (int j = 0; j < P; j++)
        operators.push_back('+');
    cin >> M;
    for (int j = 0; j < M; j++)
        operators.push_back('-');
    cin >> MT;
    for (int j = 0; j < MT; j++)
        operators.push_back('*');
    cin >> D;
    for (int j = 0; j < D; j++)
        operators.push_back('/');

    solution(A, operators);
    solution_recursive(A, A.size(), 1, A[0], P, M, MT, D);

    cout << g_r << endl << l_r << endl;
    return 0;
}
