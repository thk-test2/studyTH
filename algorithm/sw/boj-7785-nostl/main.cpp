#include <iostream>

using namespace std;

#define MAX_TABLE 1000003
#define MAX_PEOPLE 1001000

using ull = unsigned long long;

struct DB
{
    string name;
    bool in;
};

struct HASH {
    DB* db;
    HASH* next;
};

DB dbList[MAX_PEOPLE];
DB enterList[MAX_PEOPLE];
DB b[1000100];

HASH Hash[MAX_TABLE];
HASH Pool[MAX_TABLE];
int pcnt;

ull myhash(string str) {
    ull hash = 5381;
    for (auto& itr: str) {
        hash = (((hash << 5) + hash) + itr) % MAX_TABLE;
    }
    return hash % MAX_TABLE;
}

void merge(int start, int end) {
    int mid, i, j, k;

    mid = (start + end) >> 1;
    i = start;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= end) {
        if (enterList[i].name > enterList[j].name)
            b[k++] = enterList[i++];
        else
            b[k++] = enterList[j++];
    }
    while (i <= mid) b[k++] = enterList[i++];
    while (j <= end) b[k++] = enterList[j++];
    for (i = start; i <= end; i++)
        enterList[i] = b[i-start];
}

void sort(int start, int end)
{
    int mid;
    if (start == end) return;

    mid = (start + end) >> 1;
    sort(start, mid);
    sort(mid + 1, end);
    merge(start, end);
}

void push(string name, int& count) {
    dbList[count].name = name;
    dbList[count].in = true;

    ull h = myhash(name);

    HASH *nd = &Pool[pcnt++];
    nd->db = &dbList[count++];

    nd->next = Hash[h].next;
    Hash[h].next = nd;
}

void leave(string name) {
    ull h = myhash(name);
    HASH *nd = Hash[h].next;

    while (nd) {
        if (nd->db->name == name && nd->db->in) {
            nd->db->in = false;
            break;
        }
        nd = nd->next;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int count = 0;
    string name, cmd;
    for (int i = 0; i < N; i++) {
        cin >> name >> cmd;
        if (cmd == "enter") {
            push(name, count);
        } else {
            leave(name);
        }
    }
    int inCnt = 0;
    for (int i = 0; i < pcnt; i++) {
        if (dbList[i].in)
            enterList[inCnt++] = dbList[i];
    }
    sort(0, inCnt);
    for (int i = 0; i < inCnt; i++) {
//        cout << enterList[i].name << "\n";
        printf("%s\n", enterList[i].name.c_str());
    }

    return 0;
}
