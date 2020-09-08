#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<int> v;
vector<int> res;
int main()
{
	cin >> N;
	v.resize(N, 0);
	res.resize(N, 0);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	
	stack<pair<int, int>> st; // 높이, index
	for (int i = N - 1; i >= 0; i--) {
		while (!st.empty() && v[i] > st.top().first) {
			res[st.top().second] = i + 1;
			st.pop();
		}
		st.push({ v[i],i });
	}

	for (int i = 0; i < N; i++)
		cout << res[i] << " ";
}