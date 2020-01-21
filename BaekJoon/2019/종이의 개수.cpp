#include <iostream>
using namespace std;
int p[3000][3000];
int res[3];
int N;
 void paper(int size, int a, int b)
{
	 int num = p[a][b];
	 bool tmp = true;
	 for (int i = a; i < a + size; i++) {
		 for (int j = b; j < b + size; j++) {
			 if (p[i][j] != num) {
				 tmp = false;
				 break;
			 }
		 }
	 }
	 if (tmp == true) res[num + 1]++;
	 else {
		 for (int i = a; i < a + size; i += (size / 3)) {
			 for (int j = b; j < b + size; j += (size / 3)) {
				 paper(size / 3, i, j);
			 }
		 }
	 }
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> p[i][j];
		}
	}
	paper(N, 1, 1);
	for (int i = 0; i < 3; i++) 
		cout << res[i] << "\n";

	return 0;	
}