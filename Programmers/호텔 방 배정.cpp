#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<long long, long long> m;

long long find(long long n) {
	if (m[n] == 0) return n;
	return m[n] = find(m[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	
	for (int i = 0; i < room_number.size(); i++) {
		long long cur = room_number[i];
			cur = find(cur);
			answer.push_back(cur);
			m[cur] = find(cur + 1);
	}
	return answer;
}

int main()
{
	vector<long long> ans = solution(10, { 1,3,4,1,3,1 });
	for (int i=0;i<ans.size();i++) 
		cout << ans[i] << " ";
}