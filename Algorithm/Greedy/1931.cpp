#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int,int> a, const pair<int,int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int solution(int N, vector<pair<int,int>> rooms) {
    int answer = 1;
    int cmp = 0;

    sort(rooms.begin(), rooms.end(), compare);
    cmp = rooms.front().second; // 끝나는 시간
    for (int i= 1; i < rooms.size(); ++i)
    {
        if (cmp <= rooms[i].first)
        {
            cmp = rooms[i].second;
            answer++;
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<pair<int,int>> rooms;

    cin >> N;
    rooms = vector<pair<int,int>> (N);

    for (int i = 0; i < N; ++i)
    {
        cin >> rooms[i].first >> rooms[i].second;
    }

    cout << solution(N, rooms);

    return 0;
}