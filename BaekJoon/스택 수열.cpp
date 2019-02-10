#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int p[100001];
stack<int> s;
vector<char> v;
int main()
{
	int N;
	bool tmp = false;
	bool a = true;
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> p[i];

	int i = 1;
	int j = 1;
	while (true) {
		if (j <= N && s.empty()) {
			s.push(j++);
			v.push_back('+');
		}
		else if (j > N && s.empty()) break;

		else if (p[i] > s.top()) {
			s.push(j++);
			v.push_back('+'); 
		}
		else if (p[i] == s.top()) {
			v.push_back('-'); 
			i++;
			s.pop();
		}
		else break;
	}
	if (!s.empty()) cout << "NO";
	else 
		for (int i = 0; i < v.size(); i++) {
			printf("%c\n", v[i]);
		}
}