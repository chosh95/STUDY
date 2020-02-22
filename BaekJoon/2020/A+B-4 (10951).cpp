#include <iostream>
using namespace std;

int main()
{
	int A, B;

	// 방식 1
	while (cin >> A >> B) {
		cout << A + B << endl;
	}

	//방식 2
	while (scanf("%d %d", &A, &B) != EOF) {
		printf("%d\n", A + B);
	}
}