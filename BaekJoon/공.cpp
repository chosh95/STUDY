#include <iostream>
using namespace std;
int p[4] = { 0,1,0,0 };
void swap(int a, int b)
{
	int tmp = p[a];
	p[a] = p[b];
	p[b] = tmp;
}

int main()
{
	
	int M;
	cin >> M;
	int x, y;
	while (M--) {
		cin >> x >> y;
		swap(x,y);
	}
	for (int i = 1; i <= 3; i++) {
		if (p[i] == 1) {
			cout << i;
			break;
		}
	}
}