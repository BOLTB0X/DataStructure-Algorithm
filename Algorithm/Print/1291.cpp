#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
    int n,m;

    while (1) {
        cin >> n >> m;

        if (n < 2 || m < 2 || n > 9 || m > 9)
        {
            cout << "INPUT ERROR!\n";
            continue; 
        }

        for (int i = 1; i <= 9; ++i) {
            if (n < m) {
                for (int j = n; j <= m; ++j) {
                    cout << j << " * " << i << " = " << setw(2) << j * i;
                    cout << "   ";
                }
            } else {
                for (int j = n; j >= m; --j) {
                    cout << j << " * " << i << " = " << setw(2) << j * i;
                    cout << "   ";
                }
            }
            cout << '\n';
        }
        break;
    }
    return 0;
}