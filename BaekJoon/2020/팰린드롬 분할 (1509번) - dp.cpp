#include <iostream>
#include <memory.h>
#include <string>
#include <algorithm>
using namespace std;

string origin;
bool dp[2502][2502];
int visit[2502];
int n, answer = 5000;

int main()
{
    cin >> origin;
    origin = " " + origin; // 인덱싱을 위해 공백을 앞에 추가
    n = origin.size();
    memset(dp, false, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        dp[i][i] = true;
        if (i == n) break;
        if (origin[i] == origin[i + 1]) dp[i][i + 1] = true;
    }

    for (int i = 2; i < n; i++)
        for (int j = 1; j + i <= n; j++)
            if (origin[j] == origin[j + i] && dp[j + 1][j + i - 1])
                dp[j][j + i] = true;

    for (int i = 1; i < n; i++) visit[i] = 5000;
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            if (dp[j][i] && visit[i] > visit[j - 1] + 1) {
                visit[i] = visit[j - 1] + 1;
            }
        }
    }   

    cout << visit[n-1];
}