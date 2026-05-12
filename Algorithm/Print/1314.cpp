// 1314 문자사각형 2
#include <cstdio>

char board[101][101] = {0, };

int main(void) {
    int n;
    char alp = 'A';
    scanf("%d", &n);

    for (int i = 1; i <= n;++i) {
        if (i % 2) {
            for (int j = 1; j <= n; ++j) {
                board[j][i] = alp++;

                if (alp > 'Z')
                    alp = 'A';
            }
        }

        else {
            for (int j = n; j >= 1; --j) {
                board[j][i] = alp++;

                if (alp > 'Z')
                    alp = 'A';
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j  <= n; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}