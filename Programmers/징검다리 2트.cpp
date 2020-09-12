#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int lo = 0, hi = distance;
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        int cnt = 0, last = 0;
        for (int i = 0; i < rocks.size(); i++) {
            if (rocks[i] - last < mid) cnt++;
            else last = rocks[i];
        }

        if (cnt > n) hi = mid - 1;
        else lo = mid + 1;
    }

    return lo - 1;
}

int main()
{
    cout << solution(25, { 1, 3, 4, 10, 15, 20 }, 2);
}