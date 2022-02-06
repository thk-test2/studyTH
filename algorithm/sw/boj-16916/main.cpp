#include <iostream>
#include <vector>

using namespace std;

vector<int> getPartialMatch(string& search){
    int m = search.size();
    vector<int> pi(m, 0);

    int begin = 1, matched = 0;
    while (begin+matched < m) {
        if (search[begin+matched] == search[matched]) {
            matched++;
            pi[begin+matched -1] = matched;
        }
        else {
            if (matched == 0)
                begin++;
            else {
                begin = begin + matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }

    return pi;
}

bool kmp(string& source, string& search) {
    vector<int> pi = getPartialMatch(search);

    int begin = 0;
    int matched = 0;
    int n = source.size(), m = search.size();
    while (begin <= n - m) {
        if (matched < m && source[begin+matched] == search[matched]) {
            matched++;
            if (matched == m) {
                return true;
            }
        }
        else {
            if (matched == 0)
                begin++;
            else {
                begin = begin + matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S, P;
    cin >> S >> P;

    kmp(S,P) ? cout << 1 : cout << 0;

    return 0;
}
