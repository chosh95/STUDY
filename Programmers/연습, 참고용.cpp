#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main() {
	//cin, cout �ӵ� ���̱�
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//cout �Ҽ��� 6�ڸ�����
	cout << fixed;
	cout.precision(6);

	map<int, int> m;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << " " << iter->second;
	}

	set<int> s;
	s.insert(1);
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}

	priority_queue<int, vector<int>, greater<int>> q; // ��������
	priority_queue<int, vector<int>, less<int>> q; // ��������

	struct compare {
		bool operator()(int a, int b) {
			return a > b;
		}
	};
	priority_queue<int, vector<int>, compare()> q; // compare ����


}