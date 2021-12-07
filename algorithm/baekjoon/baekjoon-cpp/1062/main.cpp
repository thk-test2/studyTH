#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
3 7
antawxtica
antaytica
antaztica
2

7 9
antarotica
antajapwtica
antarnlhtica
antavfytica
antarwtica
antaltica
antantica
4

50 15
antarctica
antahellotica
antacafsdrtica
antarngjocbtica
antarnfzojctica
antarnaffuctica
antarnaapoctica
antarnapgoctica
antardsfjoctica
antanapgoctica
antaafsdrctica
antarjhgctica
antarfjhctica
antarfbncttica
antarrtctica
antarbetrectica
antarqreufctica
antarrectica
antarqfjectica
antarafjtica
antarqvawectica
antarqofwyctica
antarvnfjctica
antarqovaeutica
antareufjectica
antarqefjtica
antarqefjectica
antaructica
antarqafdoctica
antarqictica
antarqerjictica
antarqoeictica
antarqeeictica
antarbroctica
antarbuyuoctica
antarbvuroctica
antarbiuyyctica
antarbdsfhctica
antarbquroctica
antarinfjctica
antarirjectica
antariqwctica
antariwyectica
antarigsdvctica
antarijectica
antarqegafdtica
antarqctica
antarqgoeictica
antarqtqtoetica
antarqnuyectica
30
*/

void backtracking(vector<string> v, int K) {
    if (K < 5) {
        cout << 0;
        return;
    }
    bool learned[26] = {false,};
    learned['a'-'a'] = true; learned['c'-'a'] = true; learned['i'-'a'] = true;
    learned['t'-'a'] = true; learned['n'-'a'] = true;

    char chars[21] = {'b','d','e','f','g','h','j','k','l','m','o','p','q','r','s','u','v','w','x','y','z'};

    vector<int> ind;
    int k = K-5;
    for (int i = 0; i < 21-k ; i++) {
        ind.push_back(0);
    }
    for (int i = 0; i<k; i++) {
        ind.push_back(1);
    }

    int g = 0;
    do {
        for (int i = 0; i < 21 ; i++) {
            if (ind[i] == 1) {
                learned[chars[i] - 'a'] = true;
            }
        }
        int cnt = 0;
        for (auto& itr : v) {
            for (int i = 0; i < itr.size(); i++) {
                if (learned[itr[i] - 'a'] == false)
                    break;
                if (i == itr.size()-1)
                    cnt++;
            }
        }
        g = max(g, cnt);
        for (int i = 0; i < 21 ; i++) {
            if (ind[i] == 1) {
                learned[chars[i] - 'a'] = false;
            }
        }
    } while(next_permutation(begin(ind), end(ind)));
    cout << g;
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<string> v;
    string str;

    for (int i = 0; i < N; i++) {
        cin >> str;
        v.push_back(str);
    }
    backtracking(v, K);

    return 0;
}
