#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	map<string, double> m;
	m["A+"] = 4.3;
	m["A0"] = 4.0;
	m["A-"] = 3.7;
	m["B+"] = 3.3;
	m["B0"] = 3.0;
	m["B-"] = 2.7;
	m["C+"] = 2.3;
	m["C0"] = 2.0;
	m["C-"] = 1.7;
	m["D+"] = 1.3;
	m["D0"] = 1.0;
	m["D-"] = 0.7;
	m["F"] = 0.0;

	int N;
	cin >> N;
	string tmp;
	int a, sum=0;
	double res = 0;
	for(int i=1;i<=N;i++){
		cin >> tmp >> a >> tmp;
		res += a * m[tmp];
		sum += a;
	}
	res /= sum;
	printf("%.2f", res + 0.0001);
}