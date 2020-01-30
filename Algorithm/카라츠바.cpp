#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void normalize(vector<int>& c) {
	c.push_back(0);
	for (int i = 0; i + 1 < c.size(); i++) {
		if (c[i] < 0) {
			int borrow = (abs(c[i]) + 9) / 10;
			c[i + 1] -= borrow;
			c[i] = borrow * 10;
		}
		else {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	while (c.size() > 1 && c.back() == 0) c.pop_back();
}

vector<int> multiply(const vector<int> & a, const vector<int> & b) {

	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			c[i + j] += a[i] * b[j];

	normalize(c);
	return c;
}
//a+b*(10^k);
void addTo(vector<int> & a, vector<int> & b, int k) {
	int newsize = a.size() < b.size() + k ? b.size() + k : a.size();
	while (a.size() != newsize) a.push_back(0);
	for (int i = k; i < newsize; i++) {
		a[i] = a[i] + b[i - k];
	}
	normalize(a);
}

//a-=b;를 구현한다. a>=b를 가정한다.
void subFrom(vector<int> & a, vector<int> & b) {
	for (int i = 0; i < b.size(); i++) {
		a[i] -= b[i];
	}
	normalize(a);
}

vector<int> karatsuba(const vector<int> & a, const vector<int> & b) {
	int an = a.size();
	int bn = b.size();
	int half = an / 2;


	if (an < bn) return karatsuba(b, a);
	//a가 b보다 짧을 경우 둘을 바꾼다.
	if (an == 0 || bn == 0) return vector<int>();
	//기저사례:a나 b가 비어 있는 경우
	if (an <= 50) return multiply(a, b);
	//기저사례:a가 비교적 짧은 경우 O(n^2)곱셈으로 변경.
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(half, b.size()));

	vector<int> b1(b.begin() + min<int>(half, b.size()), b.end());
	//z2=a1*b1
	vector<int> z2 = karatsuba(a1, b1);
	//z0=a0*b0
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0); addTo(b0, b1, 0);
	//z1=(a1+a0)*(b1+b0)
	vector<int> z1 = karatsuba(a0, b0);

	subFrom(z1, z2);
	subFrom(z1, z0);

	vector<int> ret;
	//ret=z0+z1*10^half+z2*10^(half*2)
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);

	return ret;
}


int main()
{

	vector<int> a, b, result;
	string number;

	cout << "첫번째 정수 입력: ";
	cin >> number;
	for (int i = number.size() - 1; i >= 0; i--)
		a.push_back(number[i] - '0');

	cout << "두번째 정수 입력: ";
	cin >> number;
	for (int i = number.size() - 1; i >= 0; i--)
		b.push_back(number[i] - '0');

	result = karatsuba(a, b);

	cout << "karatsuba 결과:";
	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i];
	cout << endl;

	return 0;
}