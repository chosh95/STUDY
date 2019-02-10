#include <iostream>
using namespace std;
int main()
{
	bool p[1000002] = { false };
	long long min, max;
	cin >> min >> max;
	for (long long i = 2; i <= 1000000; i++) {
		if (i*i > max) break;
		for (long long j = min / (i*i); i*i*j <= max; j++) {
			if (i*i*j >= min) p[i*i*j - min] = true;
		}
	}

	int count = 0;
	for (int i = 0; i < max-min+1; i++) {
		if (p[i] == false) count++;
	}
	cout << count;
}