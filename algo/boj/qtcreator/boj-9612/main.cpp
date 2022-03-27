#include <iostream>

using namespace std;

using ul = unsigned long;

#define MAX_TABLE 1007

struct Node {
    int count = 0;
    string word;
    Node* next = nullptr;
};

Node hashTable[MAX_TABLE];
Node pool[MAX_TABLE];
int pcnt = 0;
int N;

ul myhash(string str) {
    ul hash = 5381;
    int c;

    for (const auto& itr : str) {
        c = itr;
        hash = (((hash << 5) + hash) + c) % MAX_TABLE;
    }
    return hash % MAX_TABLE;
}

bool isExist(string word) {
    ul h = myhash(word);
    for (Node *p = hashTable[h].next; p; p = p->next)
        if (p->word == word)
            return true;
    return false;
}

void addCount(string word) {
    ul h = myhash(word);
    for (Node* p = hashTable[h].next; p; p = p->next) {
        if (p->word == word) {
            p->count++;
            return;
        }
    }
}

void addWord(string word) {
    ul h = myhash(word);
    Node *nd = &pool[pcnt++];

    nd->count = 1;
    nd->word = word;

    nd->next = hashTable[h].next;
    hashTable[h].next = nd;
}

int main() {
    cin >> N;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        isExist(str) ? addCount(str) : addWord(str);
    }

    int maxCount = 0;
    string answer;

    for (int i = 0; i < MAX_TABLE; i++) {
        for (Node* p = hashTable[i].next; p; p = p->next) {
//            cout << p->word << " " << p->count << endl;
            if (maxCount <= p->count) {
                if (maxCount == p->count && answer < p->word)
                    answer = p->word;
                else {
                    maxCount = p->count;
                    answer = p->word;
                }
            }
        }
    }
    cout << answer << " " << maxCount;
    return 0;
}

//int main()
//{
//    int N;
//    cin >> N;

//    map<string, int> m;
//    string str;
//    int maximum = 0;
//    for (int i = 0; i < N; i++) {
//        cin >> str;
//        m[str]++;
//        maximum = max(maximum, m[str]);
//    }

//    for (auto itr = m.rbegin() ; itr != m.rend(); itr++) {
//        if (itr->second == maximum) {
//            cout << itr->first << " " << itr->second;
//            break;
//        }
//    }

//    return 0;
//}
