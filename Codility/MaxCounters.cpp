#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int>& A) {
    vector<int> res(N, 0);
    int curMax = 0;
    int lastMax = 0;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] == N + 1) {
            lastMax = curMax;
        }
        else {
            int cur = A[i] - 1;
            if (res[cur] > lastMax) {
                res[cur]++;
            }
            else {
                res[cur] = lastMax + 1;
            }

            curMax = max(curMax, res[cur]);
        }
    }

    for (int i = 0; i < N; i++) {
        if (res[i] < lastMax) res[i] = lastMax;
    }

    return res;
}

int main()
{
    vector<int> a = { 3,4,4,6,1,4,4 };
    vector<int> res = solution(5, a);
    for (auto i : res) {
        cout << i << " ";
    }
}