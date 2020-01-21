#include <iostream>
#include <algorithm>
using namespace std;
int p[10];

int main()
{
	int sum = 0;
	int cur = 0;
	for (int i = 0; i < 10; i++) cin >> p[i];
	for (int i = 0; i < 10; i++) {
		cur += p[i];
		if (abs(100 - sum) < abs(100 -cur)) 
			break;		
		else if (abs(100 - sum) >= abs(100 - cur))
			sum += p[i];
			continue;		
	}
	cout << sum;
}