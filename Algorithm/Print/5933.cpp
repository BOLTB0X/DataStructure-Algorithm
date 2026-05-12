#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int number = 1;

	for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << i * j << ' ';
        }
		cout << '\n';
	}
	return  0;
}