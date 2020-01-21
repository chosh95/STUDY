#include <iostream>
using namespace std;
int p[2];
int main()
{
	int N,tmp;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		if (tmp == 0)  p[0]++;
		else p[1]++;
	}
	if (p[0] >= p[1]) cout << "Junhee is not cute!";
	else cout << "Junhee is cute!";
}