#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++)
        q.push({ priorities[i],i});
    sort(priorities.begin(), priorities.end());
    
    int idx = 0;
    while (!q.empty()) {
        int cur = q.front().first;
        int pos = q.front().second;
        q.pop();
        if (cur == priorities.back()) {
            priorities.pop_back();
            if (pos == location) return idx + 1;
            idx++;
        }
        else {
            q.push({ cur,pos });
        }
    }
}

int main()
{
    cout << solution({ 2,1,3,2 }, 2);
    cout << solution({ 1,1,9,1,1,1 }, 0);
}