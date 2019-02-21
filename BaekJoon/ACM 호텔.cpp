#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int H, W, N;
		cin >> H >> W >> N;
		int count = 1;
		while (true)
		{
			if (N > H) {
				N -= H;
				count++;
			}
			else {
				N *= 100;
				N += count;
				cout << N << endl;
				break;
			}
		}
	}
}