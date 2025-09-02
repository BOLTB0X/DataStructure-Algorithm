#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N, answer = 0;
    int arr[1001];

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    int curSum = 0;

    for (int i = 0; i < N; ++i)
    {
        answer += (arr[i]+curSum);
        curSum += arr[i];
    }

    cout << answer;
    return 0;
}