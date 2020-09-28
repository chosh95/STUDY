#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<long long,vector<long long>, less<long long>> q;
    for (int i = 0; i < works.size(); i++)
        q.push(works[i]);

    for (int i = 1; i <= n; i++) {
        if (q.top() < 1) continue;
        long long cur = q.top();
        q.pop();
        q.push(cur - 1);
    }

    while (!q.empty()) {
        long long cur = q.top();
        q.pop();
        answer += (cur * cur);
    }
    return answer;
}

int main()
{
    cout << solution(10, { 0 });
}