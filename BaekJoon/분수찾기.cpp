#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int count = 2;
	int level = 2;
	bool tmp = false;
	if (N == 1) {
		cout << "1/1";
		tmp = true;
	}
	while(!tmp){
		if (level % 2 == 0) {
			int i = 1; 
			int j = level;
			if (count == N) {
				cout << i << "/" << j;
				break;
			}
			while (j >= 1) {
				count++;
				i++; j--;
				if (count == N && j>=1) {
					cout << i << "/" << j;
					tmp = true;
					break;
				}
			}
			level++;
		}
		else {
			int i = level;
			int j = 1;
			if (count == N) {
				cout << i << "/" << j;
				break;
			}
			while (i >= 1) {
				count++;
				i--; j++;
				if (count == N && i>=1) {
					cout << i << "/" << j;
					tmp = true;
					break;
				}
			}
			level++;
		}
	}
}