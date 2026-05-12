#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int number = 1;

	for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
		    for (int j = 1; j <= n; ++j)
			    cout << j << ' ';
        } else {
            for (int j = n; j >= 1; --j)
			    cout << j << ' ';
        }

		cout << '\n';
	}
	return  0;
}