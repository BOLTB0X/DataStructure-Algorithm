#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX

// 그래프를 인접 행렬로 표현
int graph[6][6] = {
    {0, 1, 3, INF, INF},
    {1, 0, 8, 4, INF},
    {3, 8, 0, 10, 1},
    {INF, 4, 10, 0, 5},
    {INF, INF, 1, 5, 0}};

// 최소 가중치를 가진 정점을 찾는 함수
int findMinKey(int key[], bool included[], int n)
{
    int min = INF, minIndex;

    for (int v = 0; v < n; v++)
    {
        if (!included[v] && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// 프림 알고리즘
void primMST(int n)
{
    int parent[6];              // MST의 각 정점의 부모
    int key[6];                 // 최소 가중치 값
    bool included[6] = {false}; // MST에 포함 여부

    // 초기화
    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        parent[i] = -1;
    }

    // 시작 정점 (0번 정점) 초기화
    key[0] = 0;

    // n개의 정점을 모두 처리할 때까지 반복
    for (int count = 0; count < n - 1; count++)
    {
        // 최소 가중치 정점 선택
        int u = findMinKey(key, included, n);
        included[u] = true;

        // 선택된 정점과 연결된 정점들 갱신
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && !included[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // 결과 출력
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[parent[i]][i]);
    }
}

int main()
{
    primMST(5);
    return 0;
}
