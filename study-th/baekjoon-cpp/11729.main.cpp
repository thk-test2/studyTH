#include <iostream>

using namespace std;

static int count = 0;

void hanoi(int num, char from, char by, char to){
    count++;
    if(num == 1){
        cout << from << " " << to << endl;
        return;
    }
    hanoi(num-1, from, to, by);
    cout << from << " " << to << endl;
    hanoi(num-1, by, from, to);
}

int main() {
    int num = 0;
    cin >> num;

    hanoi(num, '1', '2', '3');

    cout << count << endl;
    return 0;
}