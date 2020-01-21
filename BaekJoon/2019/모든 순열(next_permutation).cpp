#include <iostream>
#include <algorithm>
using namespace std;
int p[10];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) p[i] = i + 1;
	do {
		for (int i = 0; i < N; i++) {
			cout << p[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(p, p + N));

}