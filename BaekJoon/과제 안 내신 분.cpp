#include <iostream>
using namespace std;

int p[31];
int main()
{
	int n;
	for (int i = 1; i <= 28; i++) {
		cin >> n;
		p[n] = 1;
	}
	for (int i = 1; i <= 30; i++) 
		if (p[i] == 0) cout << i << "\n";
	
	return 0;
}