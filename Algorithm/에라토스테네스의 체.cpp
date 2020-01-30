#include <iostream>
#include <cstring>
using namespace std;
bool isPrime[1000000];

void eratosthenes()
{
	//1은 소수가 아니다.
	isPrime[1] = false;
	for (int i = 2; i * i < 1000000; i++) {
		if (isPrime[i] == false) continue;
		for (int j = i+i; j < 1000000; j += i) {
			isPrime[j] = false;
		}
	}
	return;
}

int main()
{
	memset(isPrime, true, sizeof(isPrime));
	eratosthenes();
	for (int i = 0; i < 100; i++)
		cout << i << " is Prime Number? " << isPrime[i] << endl;

	return 0;
}