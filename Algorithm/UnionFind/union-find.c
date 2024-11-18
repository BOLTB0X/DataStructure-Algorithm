#include <stdio.h>

int parents[10001];

int Find(int x)
{
    if (x == parents[x])
        return x;
    return x = Find(parents[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x != y)
    {
        parents[x] = y;
        // if (x < y)
        //     parents[y] = x;
        // else
        //     parents[x] = y;
    }

    return;
}

int main(void)
{
    // 부모 배열 초기화
    for (int i = 1; i <= 4; ++i)
        parents[i] = i;

    Union(1, 4);
    Union(2, 4);
    Union(3, 4);

    // 각 노드의 루트를 찾아 출력
    for (int i = 1; i <= 4; ++i)
    {
        printf("노드 %d의 루트: %d\n", i, Find(i));
    }
    return 0;
}