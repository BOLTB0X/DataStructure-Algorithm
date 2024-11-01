#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, bomb;

    cin >> s;
    cin >> bomb;

    string stack = "", answer;
    int stack_size = 0, bomb_size = bomb.size();

    for (int i = 0; i < s.length(); ++i) {
        stack += s[i];
        stack_size++;

        if (stack_size < bomb_size) continue;

        bool flag = true;

        for (int j = 0; j < bomb_size; ++j) {
            if (stack[stack_size - bomb_size + j] != bomb[j]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            stack.erase(stack_size - bomb_size, stack_size);
            stack_size -= bomb_size;
        }
    }

    answer = stack.length() ? stack : "FRULA";
    cout << answer;

    return 0;
}