#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genres_info;
    unordered_map<string, vector<pair<int,int>>> detail_info;
    
    for (int i = 0; i < genres.size(); ++i) {
        genres_info[genres[i]] += plays[i];
        detail_info[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<int, string>> temp;
    
    for (auto it: genres_info) {
        temp.push_back({it.second, it.first});
    }
    
    sort(temp.begin(), temp.end(), [](auto& a, auto& b) {
        return a.first > b.first;
    });
    
    for (const pair<int, string> t: temp) {
        vector<pair<int,int>> value = detail_info[t.second];
        sort(value.begin(), value.end(), [](auto& a, auto& b) {
            if (a.second == b.second) 
                return a.first < b.first;
            return a.second > b.second;
        });
        
        int cnt = 0;
        for (const pair<int,int> v: value) {
            if (cnt > 1) break;
            answer.push_back(v.first);
            cnt++;
        }
    }
    
    return answer;
}