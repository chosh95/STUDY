#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//pi[i] = str[0..i]������ �κ� ���ڿ�����
//���λ絵 �ǰ� ���̻絵 �Ǵ� �ִ����.
//ex. aabaa�� aa�� ���̹Ƿ� pi[4] = 2;
vector<int> getPi(const string& str)
{
	int m = str.size(), j =0;
	vector<int> pi(m, 0);
	//�������� 0�̸� �ڱ� �ڽ��� ã�� ������ �ȵȴ�.
	for (int i = 1; i < m; i++) {
		while (j > 0 && str[i] != str[j])
			j = pi[j - 1];
		if (str[j] == str[i])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> kmp(const string& a, const string& b)
{
	int n = a.size(), m = b.size(), j = 0;
	vector<int> pi = getPi(b);
	vector<int> res;
	for (int i = 0; i < n; i++) {
		while (j > 0 && a[i] != b[j])
			j = pi[j - 1];
		if (a[i] == b[j]) {
			if (j == m - 1) res.push_back(i - m + 1);
			else j++;
		}
	}
	return res;
}

int main()
{
	string A, B;
	cin >> A >> B;
	vector<int> v = kmp(A, B);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}