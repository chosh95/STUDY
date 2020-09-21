#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int N;
vector<int> v;
vector<int> res;
int m[1000001];
stack<int> st;

int main() {

	cin >> N;
	v.resize(N + 1);
	res.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		m[v[i]]++;
	}

	for (int i = N; i >= 1; i--) {
		if (st.empty()) {
			st.push(v[i]);
			res[i] = -1;
		}
		else if (m[v[i]] < m[st.top()]) {
			res[i] = st.top();
			st.push(v[i]);
		}
		else {
			while (!st.empty() && m[v[i]] >= m[st.top()]) {
				st.pop();
			}
			if (st.empty()) {
				res[i] = -1;
				st.push(v[i]);
			}
			else {
				res[i] = st.top();
				st.push(v[i]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << res[i] << " ";
}