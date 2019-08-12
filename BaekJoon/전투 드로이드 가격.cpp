#include <iostream>
using namespace std;
int A, B, C, D, E;
int main()
{
	int T;
	cin >> T;
	while (T--) {
		cin >> A >> B >> C >> D >> E;
		double res = 0.0;
		res += (A*350.34 + B * 230.90 + C * 190.55 + D * 125.30 + E * 180.90);
		printf("$%.2lf\n", res);
	}
}