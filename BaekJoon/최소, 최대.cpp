<<<<<<< HEAD
#include <iostream>
#include <algorithm>
using namespace std;

int p[1000001];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i];
	sort(p, p + N);
	cout << p[0] << " " << p[N-1];
=======
#include <iostream>
#include <algorithm>
using namespace std;

int p[1000001];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i];
	sort(p, p + N);
	cout << p[0] << " " << p[N-1];
>>>>>>> 7f36c76f4ad21fe245254ea3f1b3c6e1e3bbbd90
}