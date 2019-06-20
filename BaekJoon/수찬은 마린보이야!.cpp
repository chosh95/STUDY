#include <iostream>
using namespace std;
int p[101];
int N;
int main()
{
	cin >> N;
	double sum = 0.0;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		sum += p[i];
	}
	if(sum!=0) cout << "1.00";
	else cout << "divide by zero";
}