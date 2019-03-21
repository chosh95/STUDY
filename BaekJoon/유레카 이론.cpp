#include <iostream>
using namespace std;
int num;
int p[100];
bool tmp = false;
void eureka(int sum,int cnt)
{
	if (tmp == true) return;
	if (cnt == 3 && sum == num) {
		tmp = true;
		return;
	}
	else if (cnt == 3 && sum != num) {
		return;
	}
	for (int i = 1; i <= num; i++) {
		if (sum < num && cnt < 3) {
			eureka(sum + p[i], cnt + 1);
		}
	}
}
int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= 90; i++) 
		p[i] = p[i - 1] + i;
	while (T--) {
		cin >> num;
		eureka(0,0);
		if (tmp) cout << "1\n";
		else cout << "0\n";
		tmp = false;
	}
}