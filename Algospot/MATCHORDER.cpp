#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int C, N, res;
void order(vector<int> russia, vector<int> korea)
{
	sort(russia.begin(), russia.end());
	sort(korea.begin(), korea.end());
	int idx = 0;
	for (int i = 0; i < N; i++) {
		while (idx < N && russia[i] > korea[idx]) {
			idx++;
		}
		if (idx >= N) break;
		idx++;
		res++;
	}
}
int main()
{
	cin >> C;
	while (C--) {
		cin >> N;
		res = 0;
		vector<int> russia(N);
		vector<int> korea(N);
		for (int i = 0; i < N; i++) cin >> russia[i];
		for (int j = 0; j < N; j++) cin >> korea[j];
		order(russia, korea);
		cout << res << endl;
	}
}