#include <iostream>
#include <bitset>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t1 = 1 << 3;
	cout << t1 << "\n";

	int t2 = t1 & (1 << 2);
	cout << t2 << "\n";

	int t3 = t1 | (1 << 2);
	cout << t3 << "\n";

	t1 ^= 1 << 2;
	cout << t1 << "\n";
	
	t1 ^= 1 << 2;
	cout << t1 << "\n";
	
	t1 |= 1 << 2;
	cout << t1 << "\n";

	t1 &= ~(1 << 2);
	cout << t1 << "\n";

	bitset<8> b1;
	cout << b1 << "\n";

	b1.set(3);
	cout << b1 << "\n";

	b1.flip();
	cout << b1 << "\n";
	b1.flip();

	b1 |= 1 << 2;
	cout << b1 << "\n";

	b1 &= ~(1 << 2);
	cout << b1 << "\n";
	cout << b1.to_ulong() << "\n";
	
	b1.reset(3);
	cout << b1 << "\n";
	cout << b1.to_ulong() << "\n";

	int t4 = 1;
	t4 = t4 << 1;
	cout << t4 << "\n";
	t4 = t4 << 1;
	cout << t4 << "\n";
	
	int compare = 8;
	cout << (compare & t4) << "\n";
	t4 = t4 << 1;
	cout << (compare & t4) << "\n";

	cout << (compare & (1 << 2)) << "\n";
	cout << (compare & (1 << 3)) << "\n";

	int t5 = 1 << 4;
	t5 ^= 1 << 2;
	t5 ^= 1 << 2;
	cout << t5 << "\n";
	
	cout << ((t5 >> 3) & 1) << "\n";
	cout << ((t5 >> 4) & 1) << "\n";

	return 0;
}