#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<pair<int,int>> v;
int arr[1000001];
int index[1000001];

int main()
{
	int N, max_index=0,ans_index=0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	v.push_back(make_pair(arr[0], 0));
	
	for (int i = 1; i <= N; i++) {
		if(arr[i] > v.back().first) {
			v.push_back(make_pair(arr[i], v.back().second + 1));
			index[i] = v.back().second;
		}
		else{
			int idx = v.size();
			for (int j = idx - 1; j >= 0; j--) {
				if (v[j].first < arr[i]) {
					v[j+1].first = arr[i];
					index[i] = v[j+1].second;
					break;
				}
				else if (j == 0) {
					v[0].first = arr[i];
					index[i] = 0;
				}
			}
		}
		if (max_index < index[i]) {
			max_index = index[i];
			ans_index = i;
		}
	}
	cout << v.size() << endl;

	stack<int> s;
	for (int i = ans_index, k = max_index; i >= 0; i--) {
		if (index[i] == k && arr[i] <= arr[ans_index]) {
			s.push(arr[i]);
			k--;
		}
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << s.top() << " ";
		s.pop();
	}

}