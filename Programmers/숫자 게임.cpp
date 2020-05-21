#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int aidx = 0;
	int bidx = 0;
	while(true){
		if (bidx == B.size() || aidx == A.size()) break;
		if (A[aidx] < B[bidx]) {
			answer++;
			aidx++;
			bidx++;
		}
		else
			bidx++;
	}

	return answer;
}

int main()
{
	cout << solution({ 5,1,3,7 }, { 2,4,6,8 });
}