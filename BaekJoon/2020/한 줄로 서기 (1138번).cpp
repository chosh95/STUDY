#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[11];

int main()
{
	cin >> N;
	for(int i=1;i<=N;i++) {
		int num;
		cin >> num;
		for (int j = 1; j <= N; j++) {
			if (p[j] == 0 && num == 0) {
				p[j] = i;
				break;
			}
			else if (p[j] == 0) num--;
		}
	}

	for (int i = 1; i <= N; i++)
		cout << p[i] << " ";
}