#include <iostream>

using namespace std;

int solution(int n) {
	int answer = 0;
	int tot = 0;

	// 완전탐색
	for (int i = 1; i <= n; ++i) {
		tot = i;
		int part = i;

		while (part > 0) {
			int r = part % 10;
			tot += r;
			part /= 10;
		}

		if (tot == n) {
			answer = i;
			break;
		}
	}

	return answer;
}

int main(void) {
	int n;

	cin >> n;
	int ret = solution(n);
	cout << ret;
	return 0;
}