#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int U, N;
    cin >> U >> N;
    vector<string> v[U];

    string name;
    int price;

    for (int i = 0; i < N; i++) {
        cin >> name >> price;
        v[price-1].push_back(name);
    }

    int min_cnt = 1000000;
    for (int i = 0; i < U; i++) {
        if (!v[i].empty()) {
            if (min_cnt > v[i].size())
                min_cnt = v[i].size();
        }
    }

    name = "";
    price = 0;
    for (int i = 0; i < U; i++) {
        if (v[i].size() == min_cnt) {
            name = v[i].front();
            price = i+1;
            break;
        }
    }
    cout << name << " " << price;

    return 0;
}
