#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<string, int> num; // 장르 번호 부여
vector<pair<int, int>> v[101]; // 각 장르별로 {재생 수, 고유 번호}
pair<int,int> Sum[101]; // 재생 수 , 장르 번호

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) return true;
    else if (a.first == b.first) {
        return a.second < b.second;
    }
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int genreCnt = 0;
    for (int i = 0; i < genres.size(); i++) {
        if (num[genres[i]] == 0) num[genres[i]] = ++genreCnt;
        int curGenre = num[genres[i]];
        if (Sum[curGenre].second == 0)
            Sum[curGenre].second = curGenre;
        Sum[curGenre].first += plays[i];
        v[curGenre].push_back({ plays[i],i });
    }

    sort(Sum + 1, Sum + genreCnt + 1 , greater<pair<int,int>>());
    for (int i = 1; i <= genreCnt; i++) 
        sort(v[i].begin(), v[i].end(), cmp);
    
    for (int i = 1; i <= genreCnt; i++) {
        int curGenre = Sum[i].second;
        answer.push_back(v[curGenre][0].second);
        if(v[curGenre].size()>1) answer.push_back(v[curGenre][1].second);
    }

    return answer;
}

int main()
{
    vector<int> res = solution({ "classic", "classic", "classic", "pop","ele","pop","ele" }, { 500,500,500,1000,2000,400,300 });
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}