#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int count = 3;
	for (int i = 2; i <= N; i++) {
		count += count - 1;
	}
	cout << count * count;
}