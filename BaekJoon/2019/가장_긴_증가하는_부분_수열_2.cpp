#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
	int N,tmp;
	cin >> N;
	cin >> tmp;
	v.push_back(tmp);
	for (int i = 2; i <= N; i++) {
		cin >> tmp;
		int index = v.size();
		for (int j = index-1; j >= 0; j--) {
			if (v[j] < tmp) {
				if (j == index-1) v.push_back(tmp);
				else  v[j+1] = tmp;
				break;
			}
			else if (j == 0) v[0] = tmp;
		}
	}
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	//cout << v.size();
}