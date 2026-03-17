// https://school.programmers.co.kr/learn/courses/30/lessons/468370
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Word {
    string text;
    int start;
    int end;
};

int solution(string message, vector<vector<int>> spoiler_ranges) {

    vector<Word> words;
    vector<bool> spoiler(message.size(), false);

    // spoiler mask
    for (const auto& r : spoiler_ranges)
        for (int i = r[0]; i <= r[1]; i++)
            spoiler[i] = true;

    // word parsing
    string temp;
    int start = 0;

    for (int i = 0; i < message.size(); i++) {
        if (message[i] == ' ') {
            words.push_back({temp, start, i-1});
            temp = "";
            start = i + 1;
        }
        else temp += message[i];
    }

    words.push_back({temp, start, (int)message.size()-1});

    unordered_set<string> banned;
    unordered_map<string,bool> state;

    for (auto& w : words) {

        bool spoilerWord = false;

        for (int i = w.start; i <= w.end; i++) {
            if (spoiler[i]) {
                spoilerWord = true;
                break;
            }
        }

        if (!spoilerWord)
            banned.insert(w.text);

        if (spoilerWord && !banned.count(w.text))
            state[w.text] = true;

        if (!spoilerWord && state[w.text])
            state[w.text] = false;
    }

    int answer = 0;
    for (auto& [k,v] : state)
        if (v) answer++;

    return answer;
}