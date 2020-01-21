#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int main()
{
	while (true) {
		int N, sum = 1;
		bool res = true;
		cin >> N;
		if (N == -1) return 0;
		vector<int> v;
		for (int i = 2; i*i <=  N; i++) {
			if (N%i == 0) {
				v.push_back(i);
				v.push_back(N / i);
				sum += (i + N / i);
			}
			if (sum > N) {
				res = false;
				break;
			}
		}
		if (sum==N) {
			sort(v.begin(), v.end());
			cout << N << " = 1 + ";
			for (int i = 0; i < v.size(); i++) {
				if (i == v.size() - 1) cout << v[i]<<"\n";
				else cout << v[i] << " + ";
			}
		}
		else cout << N << " is NOT perfect.\n";
	}
}