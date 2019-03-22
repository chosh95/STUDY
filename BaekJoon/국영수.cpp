#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct student {
	string name;
	int kor;
	int eng;
	int mat;
	student(string s, int a, int b, int c) : name(s), kor(a), eng(b), mat(c) {}
};
vector<student> v;
bool compare(student a, student b)
{
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.mat == b.mat) {
				return a.name < b.name;
			}
			else return a.mat > b.mat;
		}
		else
			return a.eng < b.eng;
	}
	else
		return a.kor > b.kor;

}
int main()
{
	int N;
	cin >> N;
	string str;
	int a, b, c;
	while (N--) {
		cin >> str;
		scanf("%d%d%d", &a, &b, &c);
		v.push_back(student(str, a, b, c));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
		cout << v[i].name << "\n";

	return 0;
}